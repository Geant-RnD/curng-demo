##---------------------------------------------------------------------------##
## File  : curng/cmake/curng_add_library.cmake
##---------------------------------------------------------------------------##

#[=======================================================================[.rst:

CURNGUtils
-----------------

Utility commands for the CURNG example project.

.. command:: curng_add_library

  Create a new library with C++ and CUDA sources::

    curng_add_library(<name>
                     [PACKAGE <package_name>]
                     [SOURCES <file>...]
                     [POLYSOURCES <file>...]
                     )


  ``PACKAGE``
    Subdirectory of the main source directory.

  ``SOURCES``
    List of C++-only source files relative to the parent package directory, *or*
    absolute paths (for generated files).

  ``POLYSOURCES``
    List of sources that will autogenerate CUDA files when enabled. These must
    be relative to the parent package directory; absoulte paths are not allowed.

  .. note::

    This command interacts with the following variables in the parent package::

      CURNG_USE_CUDA
      CURNG_CUDA_FLAGS
      CURNG_SRC_DIR
      CURNG_GENSRC_DIR
      CURNG_LIBRARIES

.. command:: curng_configure_version

  Read the git version and tags, and configure a C++ file that exports the
  version values::

    curng_configure_version(<output>)

  ``OUTPUT``
    Path to the .cpp file that is generated.

  Assumes ``CURNG_VERSION`` and related are set by the CMake ``project``
  command.  Sets ``CURNG_VERSION_STRING`` in the parent scope.

#]=======================================================================]

set(_CURNG_CMAKE_DIR "${CMAKE_CURRENT_LIST_DIR}")

function(curng_configure_version OUTPUTFILE)
  # Get a possible Git version generated using git-archive (see the
  # .gitattributes file)
  file(STRINGS "${_CURNG_CMAKE_DIR}/git-version.txt"
       CURNG_VERSION_STRING)

  if (NOT CURNG_VERSION_STRING MATCHES "\\$Format:")
    # First line are decorators, second is hash
    list(GET CURNG_VERSION_STRING 0 _tag)
    string(REGEX REPLACE "tag: *" "" _tag "${_tag}")
    list(GET CURNG_VERSION_STRING 1 _hash)
    string(REGEX REPLACE " +" "" _hash "${_hash}")
    set(CURNG_VERSION_STRING "${_tag}-g${_hash}")
  else()
    find_package(Git)
    if (Git_FOUND)
      execute_process(
        COMMAND "${GIT_EXECUTABLE}" "describe"
        ERROR_QUIET
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        OUTPUT_VARIABLE CURNG_VERSION_STRING
        OUTPUT_STRIP_TRAILING_WHITESPACE
        )
    else()
      set(CURNG_VERSION_STRING "${CURNG_VERSION}")
    endif()
  endif()
  set(CURNG_VERSION_STRING "${CURNG_VERSION_STRING}" PARENT_SCOPE)

  # Configure the verions
  set(CURNG_VERSION_INP "${_CURNG_CMAKE_DIR}/curng_version.cpp.in")
  configure_file("${CURNG_VERSION_INP}" "${OUTPUTFILE}" @ONLY)
endfunction()

function(curng_add_library LIBNAME)
  cmake_parse_arguments(PARSE_ARGV 0 "_ARG" "" "PACKAGE" "SOURCES;POLYSOURCES")

  if (_ARG_PACKAGE)
    set(_PACKAGE_SUBDIR "${_ARG_PACKAGE}/")
  endif()

  set(_SOURCES)
  foreach(_FILENAME IN LISTS _ARG_SOURCES)
    if (NOT IS_ABSOLUTE "${_FILENAME}")
      set(_FILENAME "${CURNG_SRC_DIR}/${_PACKAGE_SUBDIR}${_FILENAME}")
    endif()
    list(APPEND _SOURCES "${_FILENAME}")
  endforeach()

  foreach(_FILENAME IN LISTS _ARG_POLYSOURCES)
    if (IS_ABSOLUTE _FILENAME)
      message(SEND_ERROR
        "Polyglot source '${_FILENAME}' must be a relative path")
    endif()
    set(_FILENAME "${_PACKAGE_SUBDIR}${_FILENAME}")

    # Add C++ source file
    list(APPEND _SOURCES "${CURNG_SRC_DIR}/${_FILENAME}")

    if (USE_CUDA)
      get_filename_component(_CU_FILENAME "${_FILENAME}" NAME_WE)
      set(_CU_FILENAME
          "${CURNG_GENSRC_DIR}/${_PACKAGE_SUBDIR}${_CU_FILENAME}.cu")
      if (NOT EXISTS "${_CU_FILENAME}")
        # Generate CUDA stub
        file(WRITE "${_CU_FILENAME}"
          "#include \"${_FILENAME}\""
          "")
      endif()

      # Add stub to source file list
      list(APPEND _SOURCES "${_CU_FILENAME}")
    endif()
  endforeach()

  add_library(${LIBNAME} ${_SOURCES})

  # Compile C++ code with C++14
  target_compile_features(${LIBNAME}
    PUBLIC
      cxx_std_14
  )

  target_include_directories(${LIBNAME}
    PUBLIC
      $<BUILD_INTERFACE:${CURNG_SRC_DIR}>
      $<BUILD_INTERFACE:${CURNG_GENSRC_DIR}>
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )

  if (USE_CUDA)
    target_compile_options(${LIBNAME}
      PUBLIC $<$<COMPILE_LANGUAGE:CUDA>:${CURNG_CUDA_FLAGS}>
    )
    set_target_properties(${LIBNAME}
      PROPERTIES CUDA_SEPARABLE_COMPILATION ON
    )
  endif()

  # Set up installation
  install(TARGETS
    ${LIBNAME}
    EXPORT CURNG-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )
  # Add to list of targets to export
  set(CURNG_LIBRARIES ${CURNG_LIBRARIES} ${CURNG_NAMESPACE}${LIBNAME}
    PARENT_SCOPE
  )
endfunction()

##---------------------------------------------------------------------------##
## end of curng/cmake/curng_add_library.cmake
##---------------------------------------------------------------------------##

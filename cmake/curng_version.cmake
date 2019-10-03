#---------------------------------------------------------------------------#
# \file cmake/curng_version.cmake
#
# Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
# Distributed under an MIT open source license: see LICENSE for details.
#---------------------------------------------------------------------------#

# Get a possible Git version generated using git-archive (see the .gitattributes
# file)
file(STRINGS "${CMAKE_CURRENT_LIST_DIR}/git-version.txt"
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

set(CURNG_VERSION_INP "${CMAKE_CURRENT_LIST_DIR}/curng_version.cpp.in"

macro(curng_configure_version OUTPUTFILE)
  configure_file("${CURNG_VERSION_INP}" "${OUTPUTFILE}" @ONLY)
endmacro()

#---------------------------------------------------------------------------#
# \file CMakeLists.txt
#
# Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
# Distributed under an MIT open source license: see LICENSE for details.
#---------------------------------------------------------------------------#

cmake_minimum_required(VERSION 3.14)
project(CURNG VERSION 0.0.1 LANGUAGES CXX)

#---------------------------------------------------------------------------#
# OPTIONS
#---------------------------------------------------------------------------#

if (CURNG_DEV OR CURNG_BUILD_EXAMPLES OR CURNG_BUILD_TESTS)
  set(_DEFAULT_BUILD_TESTING ON)
endif()

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_TESTING "Enable CTest" ${_DEFAULT_BUILD_TESTING})
option(CURNG_BUILD_EXAMPLES "Build examples" ON)
option(CURNG_BUILD_TESTS "Build CURNG tests" ${BUILD_TESTING})
option(CURNG_USE_CUDA "Enable CUDA compilation" ON)

#---------------------------------------------------------------------------#
# FLAGS
#---------------------------------------------------------------------------#

set(CURNG_CUDA_FLAGS "" CACHE PATH "Extra CUDA flags to use with CURNG")

# Build type
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  if (CURNG_DEV)
    set(_CMAKE_BUILD_TYPE "Debug")
  else ()
    set(_CMAKE_BUILD_TYPE "RelWithDebInfo")
  endif()
  message(STATUS "No build type selected, default to ${_CMAKE_BUILD_TYPE}")
  set(CMAKE_BUILD_TYPE "${_CMAKE_BUILD_TYPE}" CACHE STRING "Build type" FORCE)
endif()

#---------------------------------------------------------------------------#
# MODULES TO LOAD
#---------------------------------------------------------------------------#

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Enable testing based on BUILD_TESTING flag
include(CTest)

# CURNG utility scripts
include(CURNGUtils)

#---------------------------------------------------------------------------#
# LIBRARY
#---------------------------------------------------------------------------#

include(GNUInstallDirs)

set(CURNG_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/packages")
set(CURNG_GENSRC_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(CURNG_INSTALL_CONFIGDIR "${CMAKE_INSTALL_LIBDIR}/cmake/CURNG")
set(CURNG_NAMESPACE CURNG::)

if (CURNG_USE_CUDA)
  enable_language(CUDA)
endif()

set(CURNG_VERSION_CPP "${CURNG_GENSRC_DIR}/curng/version.cpp")
curng_configure_version("${CURNG_VERSION_CPP}")
message(STATUS "CURNG version: ${CURNG_VERSION_STRING}")

curng_add_library(curng
  PACKAGE curng
  SOURCES
    "${CURNG_VERSION_CPP}"
  POLYSOURCES
    Kernel.cpp
    MultiStateVector.cpp
  )

#---------------------------------------------------------------------------#
# Configuration file

set(HAVE_CUDA ${CURNG_USE_CUDA})
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in
  ${CURNG_GENSRC_DIR}/curng/config.h
  @ONLY)

#---------------------------------------------------------------------------#
# INSTALLATION
#---------------------------------------------------------------------------#

# Install header files
install(
  DIRECTORY "${CURNG_SRC_DIR}/"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
  REGEX "^(.(cu|cpp)|detail)$" EXCLUDE
)

# Install configure file
install(
  FILES "${CURNG_GENSRC_DIR}/curng/config.h"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/curng/"
)

install(EXPORT CURNG-targets
  FILE CURNGTargets.cmake
  NAMESPACE ${CURNG_NAMESPACE}
  DESTINATION ${CURNG_INSTALL_CONFIGDIR}
)

# Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)

configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/CURNGConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/CURNGConfig.cmake"
  INSTALL_DESTINATION ${CURNG_INSTALL_CONFIGDIR}
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/CURNGConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/CURNGConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/CURNGConfigVersion.cmake"
  DESTINATION ${CURNG_INSTALL_CONFIGDIR}
)

#---------------------------------------------------------------------------#
# TESTING AND DOCS
#---------------------------------------------------------------------------#

if (CURNG_BUILD_TESTS)
  add_subdirectory(test)
endif()

if (CURNG_BUILD_EXAMPLES)
  add_subdirectory(example)
endif()


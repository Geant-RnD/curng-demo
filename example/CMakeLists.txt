#---------------------------------------------------------------------------#
# \file example/CMakeLists.txt
#
# Copyright (c) 2019 Oak Ridge National Laboratory, UT-Battelle, LLC.
# Distributed under an MIT open source license: see LICENSE for details.
#---------------------------------------------------------------------------#

add_executable(example
  example.cc
  )
target_link_libraries(example curng)
install(TARGETS
  example
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
  )

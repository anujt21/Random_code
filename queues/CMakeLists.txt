project(Queues_from_linked_list C CXX)
cmake_minimum_required(VERSION 3.0)

set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 17)

if (NOT TESTING_ONLY)
  add_subdirectory(src)
endif()


if (TESTING OR TESTING_ONLY)
  enable_testing()
  add_subdirectory(tester)
endif()


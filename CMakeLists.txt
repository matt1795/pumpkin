cmake_minimum_required (VERSION 2.6)
project (pumpkin CXX)

# version number
set (PUMPKIN_VERSION_MAJOR 0)
set (PUMPKIN_VERSION_MINOR 1)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")

include_directories ("${PROJECT_SOURCE_DIR}/inc")

# compile example programs
add_subdirectory(examples)

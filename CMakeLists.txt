cmake_minimum_required(VERSION 3.23.2)

set(ProjectName Linear-Algebra-Library)
project(${ProjectName} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(googletest)

add_library(${ProjectName} INTERFACE)
target_include_directories(${ProjectName} INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_subdirectory(include)
add_subdirectory(test)
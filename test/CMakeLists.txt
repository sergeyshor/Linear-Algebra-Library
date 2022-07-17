cmake_minimum_required(VERSION 3.23.2)

set(TestName LinearAlgebraTest)

set(Sources ${TestName}.cpp)

add_executable(${TestName} ${Sources})
target_link_libraries(${TestName} 
    Linear-Algebra-Library
    gtest
    gtest_main
)

add_test(NAME {TestName} COMMAND {TestName})
# **Linear-Algebra-Library**
A header-only template library with implementation of Linear Algebra tools and methods for C++
## **Table of Contents**
- [About](#about)
- [License](#license)
- [Requirements](#requirements)
- [Installation](#installation) 
- [Building](#building) 
- [Documentation](#documentation)

## **About**
Linear Algebra Library is a C++ project that provides access to different Linear Algebra tools and methods. It can be used in other projects or to help students understand and learn Linear Algebra.

Current version of library contains:
- Own Matrix class with different methods to operate with it;
- Different methods to solve a system of linear equations;
- And some other functions.

Full list of tools and methods can be viewed in [Documentation](https://github.com/SergeyShor/Linear-Algebra-Library/blob/main/docs/Documentation.md).

I am looking forward to add new functionality soon such as:
- Boolean (binary) Matrix implementation;
- Matrix class iterator;
- Vector class;
- New methods to solve system of linear equations;
- Complex number class.

## **License**
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://choosealicense.com/licenses/mit/)

## **Requirements**
Linear Algebra Library requires **C++14** standard or newer.

### **Build System**
- [CMake](https://cmake.org/)

### **Testing Framework**
- [GoogleTest](https://google.github.io/googletest/)

## **Installation**

### 1. Clone the repository from [GitHub](https://github.com/SergeyShor/Linear-Algebra-Library)
**PATH** = path to clone repository
```console
>> cd <PATH>
>> git clone --recursive https://github.com/SergeyShor/Linear-Algebra-Library.git
```

### 2. Build installed products using CMake
```console
>> cd Linear-Algebra-Library
>> mkdir build
>> cd build
>> cmake ..
```

### 3. Install the includes and CMake target files 
You may need to open a command prompt with **admin privileges** on Windows.
You should run the following command with `sudo` on Linux.
```console
>> cmake --build .
```

### 4. Run the tests *(Optional)*
```console
>> cd test/Debug
```
### **Windows**
```console
>> LinearAlgebraTest.exe
```
### **Linux**
```console
>> ./LinearAlgebraTest.exe
```

## **Building**

### 1. Create the source file
```cpp
#include <iostream>
#include <LinearAlgebra.hpp>

int main() 
{
    LinAlg::Matrix<double> matrix = { { -11, 5, 4 }, { 8, 0, 31 }, { 27, -3, 16 } };
    std::cout << matrix.determinant() << '\n'; // matrix determinant calculation
    return 0;
}
```

### 2. Create the CMakeLists.txt file
```cmake
cmake_minimum_required(VERSION 3.23.2)

project(MainProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(Sources main.cpp)

add_executable(MainProject ${Sources})

add_subdirectory(Linear-Algebra-Library)

target_link_libraries(
    MainProject
    Linear-Algebra-Library
)
```

### 3. Build the project
**SRC_PATH** = path to created `CMakeLists.txt` and `main.cpp` files
```console
>> cd <SRC_PATH>
>> mkdir build
>> cd build
>> cmake ..
>> cmake --build . --config Release
```

### 4. Run the executable file
```console
>> cd Release
```
### **Windows**
```console
>> MainProject.exe
```
### **Linux**
```console
>> ./MainProject
```

## **[Documentation](https://github.com/SergeyShor/Linear-Algebra-Library/blob/main/docs/Documentation.md)**
# **Linear-Algebra-Library Documentation**

Full documentation of Linear Algebra Library.

## **Table of Contents**
- [Installation](#installation) 
- [Building](#building)
- [Namespaces](#namespaces)
- [Classes](#classes)
- [Functions](#functions)
- [Files](#files)

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
>> ./LinearAlgebraTest
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

## **Namespaces**

`LinAlg` namespace holds all tools of Linear Algebra Library.

## **[Classes](https://github.com/SergeyShor/Linear-Algebra-Library/blob/main/docs/markdown/Classes.md)**

## **[Functions](https://github.com/SergeyShor/Linear-Algebra-Library/blob/main/docs/markdown/Functions.md)**

## **[Files](https://github.com/SergeyShor/Linear-Algebra-Library/blob/main/docs/markdown/Files.md)**
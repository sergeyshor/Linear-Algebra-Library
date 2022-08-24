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

## **[Documentation](https://github.com/SergeyShor/Linear-Algebra-Library/blob/main/docs/Documentation.md)**
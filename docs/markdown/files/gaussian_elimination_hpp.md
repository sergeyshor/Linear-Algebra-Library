# Description of gaussian_elimination.hpp file
```cpp
#include <stdexcept>

#include "LinearAlgebra/Matrix.hpp"
```
## About
This file holds the Gaussian elimination method implementation used for solving systems of linear equations.
## Functions
```cpp
template <typename T>
Matrix<T> gaussian_elimination(const Matrix<T>& lhs, const Matrix<T>& rhs)
```
### [Go to the source file](https://github.com/SergeyShor/Linear-Algebra-Library/blob/main/include/LinearAlgebra/SolutionSLE/gaussian_elimination.hpp)
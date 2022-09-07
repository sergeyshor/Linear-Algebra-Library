# Description of `inverse_matrix_method` function
#### [Go back](https://github.com/SergeyShor/Linear-Algebra-Library/blob/main/docs/markdown/Functions.md)
---
```cpp
template <typename T>
Matrix<T> inverse_matrix_method(const Matrix<T>& lhs, const Matrix<T>& rhs)
```
### [Go to the source](https://github.com/SergeyShor/Linear-Algebra-Library/blob/main/include/LinearAlgebra/SolutionSLE/inverse_matrix_method.hpp#:~:text=inline%20Matrix%3CT%3E-,inverse_matrix_method,-(const%20Matrix )
---
### Namespace 
`LinAlg`
### **Parameters**
- **lhs** - matrix of independent variables;
- **rhs** - matrix of dependent variables.
### **Return value**
Matrix containing solution to the linear system.
### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if **lhs** matrix is not square;
- [std::runtime_error](https://en.cppreference.com/w/cpp/error/runtime_error) if **lhs** matrix is not invertible;
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if columns of the inverse of **lhs** matrix and **rhs** rows are not equal.

### **About**
Solves system of linear equations (or matrix equation) using inverse matrix method and returns solution to it[^1].

[^1]: Calculation accuracy is higher when using floating-point types.
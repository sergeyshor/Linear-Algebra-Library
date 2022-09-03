# Description of `gaussian_elimination` function
```cpp
template <typename T>
Matrix<T> gaussian_elimination(const Matrix<T>& lhs, const Matrix<T>& rhs)
```
### Namespace 
`LinAlg`
#### **Parameters**
- **lhs** - matrix of independent variables;
- **rhs** - matrix of dependent variables.
#### **Return value**
Matrix containing solution to the linear system.
#### **Exceptions**
- [std::runtime_error](https://en.cppreference.com/w/cpp/error/runtime_error) if the rank of the matrix of independent variables is less than the rank of the augmented matrix then the linear system is inconsistent;
- [std::runtime_error](https://en.cppreference.com/w/cpp/error/runtime_error) if the rank of the matrix of independent variables is equal to the rank of the augmented matrix and it is less than the number of rows in the matrix of independent variables then the linear system has infinite solutions.
#### **About**
Solves system of linear equations using Gaussian elimination and returns solution to it.
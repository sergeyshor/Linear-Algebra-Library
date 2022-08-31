# Description of `Matrix` class
## Namespace 
`LinAlg`
## About
`Matrix` class is an implentation of the matrix from Linear Algebra. This implementation uses a sequence container ([std::vector](https://en.cppreference.com/w/cpp/container/vector)) to store elements of the matrix. The sequence container has been chosen because the memory layout is contiguous for 1D array, which makes it more memory and speed efficient. The `std::vector` size is determined by the number of rows and columns of the matrix. Many different [public member functions](#public-member-functions) have been implemented in the `Matrix` class in order to make it more user-friendly and to provide a wide range of functionality.
## Public member functions
Constructors & Destructor|
:---:|
[Matrix](#default-constructor)()|
[Matrix](#zero-initialization-constructor)(std::size_t rows, std::size_t cols)|
[Matrix](#value-constructor)(std::size_t rows, std::size_t cols, T value)|
[Matrix](#vector-constructor)(std::size_t rows, std::size_t cols, const std::vector<T>& v)|
[Matrix](#initializer-list-constructor)(std::initializer_list< std::initializer_list<T> > il)|
[Matrix](#copy-constructor)(const Matrix<T>& other) = default|
[Matrix](#move-constructor)(Matrix<T>&& other) noexcept|
[~Matrix](#destructor)() = default|

Operators|
:---:|
T& [operator()](#operator) (std::size_t row, std::size_t col)|
const T& [operator()](#operator) (std::size_t row, std::size_t col) const|
Matrix<T>& [operator=](#operator-1) (const Matrix<T>& other) = default|
Matrix<T>& [operator=](#operator-2) (Matrix<T>&& other) noexcept|
Matrix<T> [operator*](#operator-3) (T value)|
Matrix<T> [operator/](#operator-4) (T value)|
Matrix<T> [operator*=](#operator-5) (T value)|
Matrix<T> [operator/=](#operator-6) (T value)|
Matrix<T> [operator-](#operator-) ()|
Matrix<T> [operator+](#operator-7) (const Matrix<T>& other)|
Matrix<T> [operator-](#operator--1) (const Matrix<T>& other)|
Matrix<T> [operator*](#operator-8) (const Matrix<T>& other)|
Matrix<T> [operator/](#operator-9) (const Matrix<T>& other)|
Matrix<T> [operator+=](#operator-10) (const Matrix<T>& other)|
Matrix<T> [operator-=](#operator--2) (const Matrix<T>& other)|
Matrix<T> [operator*=](#operator-11) (const Matrix<T>& other)|
Matrix<T> [operator/=](#operator-12) (const Matrix<T>& other)|

Member functions|
:---:|
std::size_t [rows](#rows)() const|
std::size_t [cols](#cols)() const|
std::size_t [vector_size](#vector_size)() const|
std::size_t [max_rows](#max_rows)()|
std::size_t [max_cols](#max_cols)()|
bool [is_square](#is_square)() const|
bool [is_zero](#is_zero)() const|
bool [is_zero_row](#is_zero_row)(std::size_t row) const|
bool [is_zero_col](#is_zero_col)(std::size_t col) const|
bool [is_row_echelon](#is_row_echelon)() const|
bool [is_symmetric](#is_symmetric)() const|
bool [is_empty](#is_empty)() const|
bool [is_invertible](#is_invertible)()|
T& [at](#at)(std::size_t row, std::size_t col)|
const T& [at](#at)(std::size_t row, std::size_t col) const|
void [set_identity](#set_identity)()|
void [set_zero](#set_zero)()|
void [set_diag](#set_diag)(const std::vector<T>& v)|
void [set_diag](#set_diag-1)(std::initializer_list<T> il)|
void [set_row](#set_row)(std::size_t row, T value)|
void [set_row](#set_row-1)(std::size_t row, const std::vector<T>& v)|
void [set_row](#set_row-2)(std::size_t row, std::initializer_list<T> il)|
void [set_col](#set_col)(std::size_t col, T value)|
void [set_col](#set_col-1)(std::size_t col, const std::vector<T>& v)|
void [set_col](#set_col-2)(std::size_t col, std::initializer_list<T> il)|
std::vector<T> [get_row](#get_row)(std::size_t row) const|
std::vector<T> [get_col](#get_col)(std::size_t col) const|
void [transpose](#transpose)()|
void [pow](#pow)(int power)|
void [swap_row](#swap_row)(std::size_t lhsRow, std::size_t rhsRow)|
void [swap_col](#swap_col)(std::size_t lhsCol, std::size_t rhsCol)|
void [mult_row](#mult_row)(std::size_t row, T value)|
void [mult_col](#mult_col)(std::size_t col, T value)|
void [add_row](#add_row)(std::size_t lhsRow, std::size_t rhsRow, T value)|
void [add_col](#add_col)(std::size_t lhsCol, std::size_t rhsCol, T value)|
void [clear](#clear)() noexcept|
void [resize](#resize)(std::size_t rows, std::size_t cols)|
void [join](#join)(const Matrix<T>& other)|
void [separate](#separate)(std::size_t col, Matrix<T>& lhs, Matrix<T>& rhs)|
void [del_row](#del_row)(std::size_t row)|
void [del_col](#del_col)(std::size_t col)|
T [cofactor](#cofactor)(std::size_t row, std::size_t col)|
T [determinant](#determinant)()|
T [rank](#rank)()|
Matrix<T> [submatrix](#submatrix)(std::size_t row, std::size_t col)|
Matrix<T> [minor](#minor)(std::size_t row, std::size_t col)|
Matrix<T> [adjoint](#adjoint)()|
Matrix<T> [inverse](#inverse)()|
Matrix<T> [row_echelon](#row_echelon)()|
Matrix<T> [back_sub](#back_sub)()|

### Friends
Friends|
:---:|
friend bool [operator==](#operator-13) (const Matrix<U>& lhs, const Matrix<U>& rhs)|
friend bool [operator!=](#operator-14) (const Matrix<U>& lhs, const Matrix<U>& rhs)|
friend Matrix<U> [operator*](#operator-15) (U value, const Matrix<U>& other)|

---
## Constructors & Destructor Description
### **Default constructor**
```cpp
template <typename T>
Matrix<T>::Matrix()
```
#### **About**
Constructs and empty matrix.

---
### Zero-initialization Constructor
```cpp
template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols)
```
#### **Parameters**
- **rows** - number of rows in the matrix;
- **cols** - number of columns in the matrix.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows >= max_rows()`[^1];
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `cols >= max_rows()`[^1];
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows != 0 && cols == 0`;
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows == 0 && cols != 0`.

#### **About**
Constructs the matrix with **rows** rows and **cols** columns and initializes its elements with the default value of T.

---
### Value Constructor
```cpp
template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols, T value)
```
#### **Parameters**
- **rows** - number of rows in the matrix;
- **cols** - number of columns in the matrix;
- **value** - value of T type to initialize the elements of the matrix with.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows >= max_rows()`[^1];
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `cols >= max_rows()`[^1];
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows != 0 && cols == 0`;
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows == 0 && cols != 0`.
#### **About**
Constructs the matrix with **rows** rows and **cols** columns and initializes its elements with the **value** value of T.

---
### Vector Constructor
```cpp
template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols, const std::vector<T>& v)
```
#### **Parameters**
- **rows** - number of rows in the matrix;
- **cols** - number of columns in the matrix;
- **v** - `std::vector` with the size of **rows**×**cols** to initialize the elements of the matrix with.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows >= max_rows()`[^1];
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `cols >= max_rows()`[^1];
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows != 0 && cols == 0`;
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows == 0 && cols != 0`;
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `v.size() != vector_size()`.
#### **About**
Constructs the matrix with **rows** rows and **cols** columns and initializes its elements with the elements of the **v** `std::vector` container.

---
### Initializer List Constructor
```cpp
template <typename T>
Matrix<T>::Matrix(std::initializer_list< std::initializer_list<T> > il)
```
#### **Parameters**
- **il** - initializer list with the nested initializer lists to initialize the elements of the matrix with.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if nested initializer lists are not the same size.
#### **About**
Constructs the matrix and initializes its rows with the corresponding nested initializer lists of the **il** initializer list.

---
### Copy Constructor
```cpp
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) = default
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **About**
Constructs the container with the copy of the contents of other.

---
### Move Constructor
```cpp
template <typename T>
Matrix<T>::Matrix(Matrix<T>&& other) noexcept
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **About**
Constructs the matrix with the contents of **other** using move semantics.

---
### Destructor
```cpp
template <typename T>
Matrix<T>::~Matrix() = default
```
#### **About**
Destructs the matrix.

---
## Operators
### operator()()
```cpp
template <typename T>
T& Matrix<T>::operator() (std::size_t row, std::size_t col)
```
```cpp
template <typename T>
const T& Matrix<T>::operator() (std::size_t row, std::size_t col) const
```
#### **Parameters**
- **row** - row of the element of the matrix to return
- **col** - column of the element of the matrix to return
#### **Return value**
Reference to the requested element.
#### **About**
Returns a reference to the element at specified row and column.

---
### operator=()
```cpp
template <typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& other) = default
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **Return value**
`*this`.
#### **About**
Copy Assignment Operator.

### operator=()
```cpp
template <typename T>
Matrix<T>& Matrix<T>::operator= (Matrix<T>&& other) noexcept
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **Return value**
`*this`.
#### **About**
Move assignment operator.

### operator*()
```cpp
template <typename T>
Matrix<T> Matrix<T>::operator* (T value)
```
#### **Parameters**
- **value** - multiplier value
#### **Return value**
Result matrix.
#### **About**
Returns the result of multiplication between the matrix as lhs and **value** value as rhs.
  
### operator/()
```cpp
template <typename T>
Matrix<T> Matrix<T>::operator/ (T value)
```
#### **Parameters**
- **value** - divider value
#### **Return value**
Result matrix.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `value == T()`.
#### **About**
Returns the result of division between the matrix and **value** value.
  
### operator*=()
```cpp
template <typename T>
Matrix<T> Matrix<T>::operator*= (T value)
```
#### **Parameters**
- **value** - multiplier value
#### **Return value**
Result matrix.
#### **About**
Returns the result of multiplication between the matrix and **value** value and assigns it to the matrix.
  
### operator/=()
```cpp
template <typename T>
Matrix<T> Matrix<T>::operator/= (T value)
```
#### **Parameters**
- **value** - divider value
#### **Return value**
Result matrix.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `value == T()`.
#### **About**
Returns the result of division between the matrix and **value** value and assigns it to the matrix.

---
### operator-()
```cpp
template <typename T>
Matrix<T> Matrix<T>::operator- ()
```
#### **Parameters**
(none)
#### **Return value**
Negative of the Matrix object.
#### **About**
Returns negative of the Matrix object.

---
### operator+()
```cpp
template <typename T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T>& other)
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **Return value**
Result matrix.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows() != other.rows() || cols() != other.cols()`.
#### **About**
Returns sum of two matrices.

---
### operator-()
```cpp
template <typename T>
Matrix<T> Matrix<T>::operator- (const Matrix<T>& other)
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **Return value**
Result matrix.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows() != other.rows() || cols() != other.cols()`.
#### **About**
Returns difference of two matrices.

---
### operator*()
```cpp
template <typename T>
Matrix<T> Matrix<T>::operator* (const Matrix<T>& other)
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **Return value**
Result matrix.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `cols() != other.rows()`.
#### **About**
Returns multiplication of two matrices.

---
### operator/()
```cpp
template <typename T>
Matrix<T> Matrix<T>::operator/ (const Matrix<T>& other)
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **Return value**
Result matrix.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`;
- [std::runtime_error](https://en.cppreference.com/w/cpp/error/runtime_error) if `!is_invertible()`.
#### **About**
Returns division of two matrices.

---
### operator+=()
```cpp
template <typename T>
Matrix<T>& Matrix<T>::operator+= (const Matrix<T>& other)
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **Return value**
`*this`.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows() != other.rows() || cols() != other.cols()`.
#### **About**
Returns the result of sum of two matrices and assigns it to the matrix.

---
### operator-=()
```cpp
template <typename T>
Matrix<T>& Matrix<T>::operator-= (const Matrix<T>& other)
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **Return value**
`*this`.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows() != other.rows() || cols() != other.cols()`.
#### **About**
Returns the result of difference of two matrices and assigns it to the matrix.

---
### operator*=()
```cpp
template <typename T>
Matrix<T>& Matrix<T>::operator*= (const Matrix<T>& other)
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **Return value**
`*this`.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `cols() != other.rows()`.
#### **About**
Returns the result of multiplication of two matrices and assigns it to the matrix.

---
### operator/=()
```cpp
template <typename T>
Matrix<T>& Matrix<T>::operator/= (const Matrix<T>& other)
```
#### **Parameters**
- **other** - another object of the Matrix class.
#### **Return value**
`*this`.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`;
- [std::runtime_error](https://en.cppreference.com/w/cpp/error/runtime_error) if `!is_invertible()`.
#### **About**
Returns the result of division of two matrices and assigns it to the matrix.

---
## Member Functions Description
### rows()
```cpp
template <typename T>
std::size_t Matrix<T>::rows() const
```
#### **Parameters**
(none)
#### **Return value**
The number of rows in the matrix.
#### **About**
Returns the number of rows in the matrix.

---
### cols()
```cpp
template <typename T>
std::size_t Matrix<T>::cols() const
```
#### **Parameters**
(none)
#### **Return value**
The number of cols in the matrix.
#### **About**
Returns the number of cols in the matrix.

---
### vector_size()
```cpp
template <typename T>
std::size_t Matrix<T>::vector_size() const
```
#### **Parameters**
(none)
#### **Return value**
The size of `std::vector` that contains the elements of the matrix.
#### **About**
Returns the size of `std::vector` that contains the elements of the matrix.

---
### max_rows()
```cpp
template <typename T>
std::size_t Matrix<T>::max_rows()
```
#### **Parameters**
(none)
#### **Return value**
The maximum possible number of rows.
#### **About**
Returns the maximum possible number of rows.

---
### max_cols()
```cpp
template <typename T>
std::size_t Matrix<T>::max_cols()
```
#### **Parameters**
(none)
#### **Return value**
The maximum possible number of cols.
#### **About**
Returns the maximum possible number of cols.

---
### is_square()
```cpp
template <typename T>
bool Matrix<T>::is_square() const
```
#### **Parameters**
(none)
#### **Return value**
`true` if the matrix is square, `false` otherwise.
#### **About**
Checks if the matrix is square.

---
### is_zero()
```cpp
template <typename T>
bool Matrix<T>::is_zero() const
```
#### **Parameters**
(none)
#### **Return value**
`true` if the matrix is zero, `false` otherwise.
#### **About**
Checks if the matrix is zero.

---
### is_zero_row()
```cpp
template <typename T>
bool Matrix<T>::is_zero_row(std::size_t row) const
```
#### **Parameters**
- **row** - row of the matrix to check
#### **Return value**
`true` if the requested row of the matrix is zero, `false` otherwise.
#### **About**
Checks if the requested row of the matrix is zero.

---
### is_zero_col()
```cpp
template <typename T>
bool Matrix<T>::is_zero_col(std::size_t col) const
```
#### **Parameters**
- **col** - column of the matrix to check
#### **Return value**
`true` if the requested column of the matrix is zero, `false` otherwise.
#### **About**
Checks if the requested column of the matrix is zero.

---
### is_row_echelon()
```cpp
template <typename T>
bool Matrix<T>::is_row_echelon() const
```
#### **Parameters**
(none)
#### **Return value**
`true` if the matrix is in row echelon form, `false` otherwise.
#### **About**
Checks if the matrix is in row echelon form.

---
### is_symmetric()
```cpp
template <typename T>
bool Matrix<T>::is_symmetric() const
```
#### **Parameters**
(none)
#### **Return value**
`true` if the matrix is symmetric, `false` otherwise.
#### **About**
Checks if the matrix is symmetric.

---
### is_empty()
```cpp
template <typename T>
bool Matrix<T>::is_empty() const
```
#### **Parameters**
(none)
#### **Return value**
`true` if the matrix is empty, `false` otherwise.
#### **About**
Checks if the matrix is empty.

---
### is_invertible()
```cpp
template <typename T>
bool Matrix<T>::is_invertible()
```
#### **Parameters**
(none)
#### **Return value**
`true` if the matrix is invertible, `false` otherwise.
#### **About**
Checks if the matrix is invertible.

---
### at()
```cpp
template <typename T>
T& Matrix<T>::at(std::size_t row, std::size_t col)
```
```cpp
template <typename T>
const T& Matrix<T>::at(std::size_t row, std::size_t col) const
```
#### **Parameters**
- **row** - row of the element of the matrix to return
- **col** - column of the element of the matrix to return
#### **Return value**
Reference to the requested element.
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `rows() < row || cols() < col`.
#### **About**
Returns a reference to the element at specified row and column with bounds checking.

---
### set_identity()
```cpp
template <typename T>
void Matrix<T>::set_identity()
```
#### **Parameters**
(none)
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`.
#### **About**
Sets the Matrix to the identity matrix.

---
### set_zero()
```cpp
template <typename T>
void Matrix<T>::set_zero()
```
#### **Parameters**
(none)
#### **Return value**
(none)
#### **About**
Sets the Matrix to the zero matrix.

---
### set_diag()
```cpp
template <typename T>
void Matrix<T>::set_diag(const std::vector<T>& v)
```
#### **Parameters**
- **v** - `std::vector` to set the elements of the diagonal of the matrix with.
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`;
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `v.size() != rows()`.
#### **About**
Sets the elements of the diagonal of the matrix with `std::vector`.

---
### set_diag()
```cpp
template <typename T>
void Matrix<T>::set_diag(std::initializer_list<T> il)
```
#### **Parameters**
- **il** - initializer list to set the elements of the diagonal of the matrix with.
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`;
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `il.size() != rows()`.
#### **About**
Sets the elements of the diagonal of the matrix with the initializer list.

---
### set_row()
```cpp
template <typename T>
void Matrix<T>::set_row(std::size_t row, T value)
```
#### **Parameters**
- **row** - row of the matrix to set;
- **value** - value of type T to set the elements of the row of the matrix with.
#### **Return value**
(none)
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `row >= rows()`.
#### **About**
Sets the elements of the **row** row of the matrix with the **value** value.

---
### set_row()
```cpp
template <typename T>
void Matrix<T>::set_row(std::size_t row, const std::vector<T>& v)
```
#### **Parameters**
- **row** - row of the matrix to set;
- **v** - `std::vector` to set the elements of the row of the matrix with.
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `v.size() != cols()`;
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `row >= rows()`.
#### **About**
Sets the elements of the **row** row of the matrix with the **v** `std::vector`.

---
### set_row()
```cpp
template <typename T>
void Matrix<T>::set_row(std::size_t row, std::initializer_list<T> il)
```
#### **Parameters**
- **row** - row of the matrix to set;
- **il** - initializer list to set the elements of the row of the matrix with.
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `il.size() != cols()`;
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `row >= rows()`.
#### **About**
Sets the elements of the **row** row of the matrix with the **il** initializer list.

---
### set_col()
```cpp
template <typename T>
void Matrix<T>::set_col(std::size_t col, T value)
```
#### **Parameters**
- **col** - column of the matrix to set;
- **value** - value of type T to set the elements of the column of the matrix with.
#### **Return value**
(none)
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `col >= cols()`.
#### **About**
Sets the elements of the **col** column of the matrix with the **value** value.

---
### set_col()
```cpp
template <typename T>
void Matrix<T>::set_col(std::size_t col, const std::vector<T>& v)
```
#### **Parameters**
- **col** - column of the matrix to set;
- **v** - `std::vector` to set the elements of the column of the matrix with.
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `v.size() != rows()`;
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `col >= cols()`.
#### **About**
Sets the elements of the **col** column of the matrix with the **v** `std::vector`.

---
### set_col()
```cpp
template <typename T>
void Matrix<T>::set_col(std::size_t col, std::initializer_list<T> il)
```
#### **Parameters**
- **col** - column of the matrix to set;
- **il** - initializer list to set the elements of the column of the matrix with.
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `il.size() != rows()`;
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `col >= cols()`.
#### **About**
Sets the elements of the **col** column of the matrix with the **il** initializer list.

---
### get_row()
```cpp
template <typename T>
std::vector Matrix<T>::get_row(std::size_t row) const
```
#### **Parameters**
- **row** - row of the matrix to return.
#### **Return value**
The `std::vector` with the **row** row of the matrix.
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `row >= rows()`.
#### **About**
Returns `std::vector` with the elements of the **row** row of the matrix.

---
### get_col()
```cpp
template <typename T>
std::vector Matrix<T>::get_col(std::size_t col) const
```
#### **Parameters**
- **col** - column of the matrix to return.
#### **Return value**
The `std::vector` with the **col** column of the matrix.
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `col >= cols()`.
#### **About**
Returns `std::vector` with the elements of the **col** column of the matrix.

---
### transpose()
```cpp
template <typename T>
void Matrix<T>::transpose()
```
#### **Parameters**
(none)
#### **Return value**
(none)
#### **About**
Transposes the matrix.

---
### pow()
```cpp
template <typename T>
void Matrix<T>::pow(int power)
```
#### **Parameters**
- **power** - power.
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`.
#### **About**
Computes the matrix raised to the power **power**.

---
### swap_row()
```cpp
template <typename T>
void Matrix<T>::swap_row(std::size_t lhsRow, std::size_t rhsRow)
```
#### **Parameters**
- **lhsRow**, **rhsRow** - rows of the matrix to be swapped.
#### **Return value**
(none)
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `lhsRow >= rows() || rhsRow >= rows()`.
#### **About**
Swaps the rows of the matrix **lhsRow** and **rhsRow**.

---
### swap_col()
```cpp
template <typename T>
void Matrix<T>::swap_col(std::size_t lhsCol, std::size_t rhsCol)
```
#### **Parameters**
- **lhsCol**, **rhsCol** - columns of the matrix to be swapped.
#### **Return value**
(none)
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `lhsCol >= cols() || rhsCol >= cols()`.
#### **About**
Swaps the columns of the matrix **lhsCol** and **rhsCol**.

---
### mult_row()
```cpp
template <typename T>
void Matrix<T>::mult_row(std::size_t row, T value)
```
#### **Parameters**
- **row** - row of the matrix to muliply;
- **value** - multiplier value.
#### **Return value**
(none)
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `row >= rows()`.
#### **About**
Multiplies the **row** row of the matrix by the **value** value.

---
### mult_col()
```cpp
template <typename T>
void Matrix<T>::mult_col(std::size_t col, T value)
```
#### **Parameters**
- **col** - column of the matrix to muliply;
- **value** - multiplier value.
#### **Return value**
(none)
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `col >= cols()`.
#### **About**
Multiplies the **col** column of the matrix by the **value** value.

---
### add_row()
```cpp
template <typename T>
void Matrix<T>::add_row(std::size_t lhsRow, std::size_t rhsRow, T value)
```
#### **Parameters**
- **lhsRow** - the row of the matrix to which the **rhsRow** row of the matrix is added;
- **rhsRow** - the row of the matrix to add;
- **value** - multiplier of the elements of the **rhsRow** row of the matrix.
#### **Return value**
(none)
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `lhsRow >= rows() || rhsRow >= rows()`.
#### **About**
Adds the **rhsRow** row of the matrix multiplied by the **value** value to the **lhsRow** row of the matrix.

---
### add_col()
```cpp
template <typename T>
void Matrix<T>::add_col(std::size_t lhsCol, std::size_t rhsCol, T value)
```
#### **Parameters**
- **lhsCol** - the column of the matrix to which the **rhsCol** column of the matrix is added;
- **rhsCol** - the column of the matrix to add;
- **value** - multiplier of the elements of the **rhsCol** column of the matrix
#### **Return value**
(none)
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `lhsCol >= cols() || rhsCol >= cols()`.
#### **About**
Adds the **rhsCol** column of the matrix multiplied by the **value** value to the **lhsCol** column of the matrix.

---
### clear()
```cpp
template <typename T>
void Matrix<T>::clear() noexcept
```
#### **Parameters**
(none)
#### **Return value**
(none)
#### **About**
Erases all elements from the matrix.

---
### resize()
```cpp
template <typename T>
void Matrix<T>::resize(std::size_t rows, std::size_t cols)
```
#### **Parameters**
- **rows** - new number of rows of the matrix; 
- **cols** - new number of columns of the matrix
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows >= max_rows()`[^1];
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `cols >= max_rows()`[^1];
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows != 0 && cols == 0`;
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows == 0 && cols != 0`.
#### **About**
Resizes the matrix to contain **rows** rows and **cols** columns.

---
### join()
```cpp
template <typename T>
void Matrix<T>::join(const Matrix<T>& other)
```
#### **Parameters**
- **other** - matrix to attach. 
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `rows() != other.rows()`.
#### **About**
Joins the matrix with the **other** matrix.

---
### separate()
```cpp
template <typename T>
void Matrix<T>::separate(std::size_t col, LinAlg::Matrix<T>& lhs, LinAlg::Matrix<T>& rhs)
```
#### **Parameters**
- **col** - number of the column to separate from the matrix;
- **lhs** - the matrix except the **col** column;
- **rhs** - the **col** column of the matrix.
#### **Return value**
(none)
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `col >= cols()`.
#### **About**
Separates the **col** column from the matrix and separates the matrix into **lhs** and **rhs** matrices.

---
### del_row()
```cpp
template <typename T>
void Matrix<T>::del_row(std::size_t row)
```
#### **Parameters**
- **row** - row to delete from the matrix.
#### **Return value**
(none)
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `row >= rows()`.
#### **About**
Deletes the **row** row from the matrix.

---
### del_col()
```cpp
template <typename T>
void Matrix<T>::del_col(std::size_t col)
```
#### **Parameters**
- **col** - column to delete from the matrix.
#### **Return value**
(none)
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `col >= cols()`.
#### **About**
Deletes the **col** column from the matrix.

---
### cofactor()
```cpp
template <typename T>
T Matrix<T>::cofactor(std::size_t row, std::size_t col)
```
#### **Parameters**
- **row** - row of the matrix containing a specified element;
- **col** - column of the matrix containing a specified element.
#### **Return value**
Determinant of the minor formed by removing **row** row and **col** column of the matrix.
### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`;
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `row >= rows()`;
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `col >= cols()`.
#### **About**
Returns determinant of the minor formed by removing **row** row and **col** column of the matrix.

---
### determinant()
```cpp
template <typename T>
T Matrix<T>::determinant()
```
#### **Parameters**
(none)
#### **Return value**
Matrix determinant.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`.
#### **About**
Returns matrix determinant. The determinant is computed via cofactor expansion.

---
### rank()
```cpp
template <typename T>
T Matrix<T>::rank()
```
#### **Parameters**
(none)
#### **Return value**
Matrix rank.
#### **About**
Returns matrix rank. The rank is computed via transforming the matrix to row echelon form.

---
### submatrix()
```cpp
template <typename T>
Matrix<T> Matrix<T>::submatrix(std::size_t row, std::size_t col)
```
#### **Parameters**
- **row** - row of the matrix containing a specified element;
- **col** - column of the matrix containing a specified element.
#### **Return value**
Submatrix of the matrix.
#### **Exceptions**
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `row >= rows()`;
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `col >= cols()`.
#### **About**
Returns submatrix formed by removing **row** row and **col** column of the matrix.

---
### minor()
```cpp
template <typename T>
Matrix<T> Matrix<T>::minor(std::size_t row, std::size_t col)
```
#### **Parameters**
- **row** - row of the matrix containing a specified element;
- **col** - column of the matrix containing a specified element.
#### **Return value**
Minor of the matrix.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`;
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `row >= rows()`;
- [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range) if `col >= cols()`.
#### **About**
Returns minor formed by removing **row** row and **col** column of the matrix.

---
### adjoint()
```cpp
template <typename T>
Matrix<T> Matrix<T>::adjoint()
```
#### **Parameters**
(none)
#### **Return value**
Adjoint of the matrix.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`.
#### **About**
Returns adjoint of the matrix.

---
### inverse()
```cpp
template <typename T>
Matrix<T> Matrix<T>::inverse()
```
#### **Parameters**
(none)
#### **Return value**
Inverse matrix.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_square()`;
- [std::runtime_error](https://en.cppreference.com/w/cpp/error/runtime_error) if `!is_invertible()`.
#### **About**
Returns inverse of the matrix.

---
### row_echelon()
```cpp
template <typename T>
Matrix<T> Matrix<T>::row_echelon()
```
#### **Parameters**
(none)
#### **Return value**
Matrix in row echelon form.
#### **About**
Returns matrix in row echelon form.

---
### back_sub()
```cpp
template <typename T>
Matrix<T> Matrix<T>::back_sub()
```
#### **Parameters**
(none)
#### **Return value**
Matrix containing the solution to the linear system.
#### **Exceptions**
- [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument) if `!is_row_echelon()`.
#### **About**
Performs the procedure of solving a system of linear equations and returns matrix containing the solution to it.

---
## Friends Description
### operator==()
```cpp
template <typename U>
friend bool operator== (const Matrix<U>& lhs, const Matrix<U>& rhs)
```
#### **Parameters**
- **lhs**, **rhs** - matrices whose contents to compare.
#### **Return value**
`true` if the contents of the matrices are equal, `false` otherwise.
#### **About**
Checks if the contents of **lhs** and **rhs** are equal, that is, they have the same number of elements and each element in **lhs** compares equal with the element in **rhs** at the same position.

---
### operator!=()
```cpp
template <typename U>
friend bool operator!= (const Matrix<U>& lhs, const Matrix<U>& rhs)
```
#### **Parameters**
- **lhs**, **rhs** - matrices whose contents to compare.
#### **Return value**
`true` if the contents of the matrices are not equal, `false` otherwise.
#### **About**
Checks if the contents of **lhs** and **rhs** are equal, that is, they have the same number of elements and each element in **lhs** compares equal with the element in **rhs** at the same position.

---
### operator*()
```cpp
template <typename U>
friend Matrix<U> operator* (U value, const Matrix<U>& other)
```
#### **Parameters**
- **value** - multiplier value
- **other** - object of the Matrix class.
#### **Return value**
Result matrix.
#### **About**
Returns the result of multiplication between **value** value as lhs and the **other** matrix as rhs.

[^1]: The negative `rows` and `cols` parameters convert to `std::size_t`. Constructors do not check for values below zero because converted negative values are more than `max_rows()` and `max_cols` values respectively.
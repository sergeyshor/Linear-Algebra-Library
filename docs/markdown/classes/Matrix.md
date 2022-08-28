# Description of ```Matrix``` class
### Namespace 
```LinAlg```
### About
### Public member functions
Constructors & Destructor|
:---:|
[Matrix]()()|
[Matrix]()(std::size_t rows, std::size_t cols)|
[Matrix]()(std::size_t rows, std::size_t cols, T value)|
[Matrix]()(std::size_t rows, std::size_t cols, const std::vector<T>& v)|
[Matrix]()(std::initializer_list< std::initializer_list<T> > il)|
[Matrix]()(const Matrix<T>& other) = default|
[Matrix]()(Matrix<T>&& other) noexcept|
[~Matrix]()() = default|

Operators|
:---:|
T& [operator()]() (std::size_t row, std::size_t col)|
const T& [operator()]() (std::size_t row, std::size_t col) const|
Matrix<T>& [operator=]() (const Matrix<T>& other) = default|
Matrix<T>& [operator=]() (Matrix<T>&& other) noexcept|
Matrix<T> [operator*]() (T value)|
Matrix<T> [operator/]() (T value)|
Matrix<T> [operator*=]() (T value)|
Matrix<T> [operator/=]() (T value)|
Matrix<T> [operator-]() ()|
Matrix<T> [operator+]() (const Matrix<T>& other)|
Matrix<T> [operator-]() (const Matrix<T>& other)|
Matrix<T> [operator*]() (const Matrix<T>& other)|
Matrix<T> [operator/]() (const Matrix<T>& other)|
Matrix<T> [operator+=]() (const Matrix<T>& other)|
Matrix<T> [operator-=]() (const Matrix<T>& other)|
Matrix<T> [operator*=]() (const Matrix<T>& other)|
Matrix<T> [operator/=]() (const Matrix<T>& other)|

Member functions|
:---:|
std::size_t [rows]()() const|
std::size_t [cols]()() const|
std::size_t [vector_size]()() const|
std::size_t [max_rows]()()|
std::size_t [max_cols]()()|
bool [is_square]()() const|
bool [is_zero]()() const|
bool [is_zero_row]()(std::size_t row) const|
bool [is_zero_col]()(std::size_t col) const|
bool [is_row_echelon]()() const|
bool [is_symmetric]()() const|
bool [is_empty]()() const|
bool [is_invertible]()()|
T& [at]()(std::size_t row, std::size_t col)|
const T& [at]()(std::size_t row, std::size_t col) const|
void [set_identity]()()|
void [set_zero]()()|
void [set_diag]()(const std::vector<T>& v)|
void [set_diag]()(std::initializer_list<T> il)|
void [set_row]()(std::size_t row, T value)|
void [set_row]()(std::size_t row, const std::vector<T>& v)|
void [set_row]()(std::size_t row, std::initializer_list<T> il)|
void [set_col]()(std::size_t col, T value)|
void [set_col]()(std::size_t col, const std::vector<T>& v)|
void [set_col]()(std::size_t col, std::initializer_list<T> il)|
std::vector<T> [get_row]()(std::size_t row) const|
std::vector<T> [get_col]()(std::size_t col) const|
void [transpose]()()|
void [pow]()(int power)|
void [swap_row]()(std::size_t lhsRow, std::size_t rhsRow)|
void [swap_col]()(std::size_t lhsCol, std::size_t rhsCol)|
void [mult_row]()(std::size_t row, T value)|
void [mult_col]()(std::size_t col, T value)|
void [add_row]()(std::size_t lhsRow, std::size_t rhsRow, T value)|
void [add_col]()(std::size_t lhsCol, std::size_t rhsCol, T value)|
void [clear]()() noexcept|
void [resize]()(std::size_t rows, std::size_t cols)|
void [join]()(const Matrix<T>& other)|
void [separate]()(std::size_t col, Matrix<T>& lhs, Matrix<T>& rhs)|
void [del_row]()(std::size_t row)|
void [del_col]()(std::size_t col)|
T [cofactor]()(std::size_t row, std::size_t col)|
T [determinant]()()|
T [rank]()()|
Matrix<T> [submatrix]()(std::size_t row, std::size_t col)|
Matrix<T> [minor]()(std::size_t row, std::size_t col)|
Matrix<T> [adjoint]()()|
Matrix<T> [inverse]()()|
Matrix<T> [row_echelon]()()|
Matrix<T> [back_sub]()()|

### Friends
Friends|
:---:|
friend bool [operator==]() (const Matrix<U>& lhs, const Matrix<U>& rhs)|
friend bool [operator!=]() (const Matrix<U>& lhs, const Matrix<U>& rhs)|
friend Matrix<U> [operator*]() (U value, const Matrix<U>& other)|

### Constructors & Destructor Description
### Member Functions Description
### Friends Description
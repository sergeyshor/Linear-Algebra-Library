#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <vector>

namespace LinAlg
{
    template <typename T>
    class Matrix
    {
    public:
        Matrix();
        Matrix(std::size_t rows, std::size_t cols);
        Matrix(std::size_t rows, std::size_t cols, T value);
        Matrix(std::size_t rows, std::size_t cols, const std::vector<T>& v);
        Matrix(std::initializer_list< std::initializer_list<T> > il);
        Matrix(const Matrix<T>& other) = default;
        Matrix(Matrix<T>&& other) noexcept;
        ~Matrix() = default;

        T& operator()(std::size_t row, std::size_t col);
        const T& operator()(std::size_t row, std::size_t col) const;

        Matrix<T>& operator= (const Matrix<T>& other) = default;
        Matrix<T>& operator= (Matrix<T>&& other) noexcept;

        Matrix<T> operator* (T value);
        Matrix<T> operator/ (T value);

        Matrix<T>& operator*= (T value);
        Matrix<T>& operator/= (T value);

        std::size_t rows() const { return _rows; }
        std::size_t cols() const { return _cols; }
        std::size_t vector_size() const { return _matrix.size(); }
        std::size_t max_rows() { return _matrix.max_size(); };
        std::size_t max_cols() { return max_rows() / _rows; };

        bool isSquare() const { return _rows == _cols; }

        T& at(std::size_t row, std::size_t col);
        const T& at(std::size_t row, std::size_t col) const;

        void set_identity();
        void set_zero();
        void set_diag(const std::vector<T>& v);
        void set_diag(std::initializer_list<T> il);
        void set_row(T value, std::size_t row);
        void set_row(const std::vector<T>& v, std::size_t row);
        void set_row(std::initializer_list<T> il, std::size_t row);
        void set_col(T value, std::size_t col);
        void set_col(const std::vector<T>& v, std::size_t col);
        void set_col(std::initializer_list<T> il, std::size_t col);

        std::vector<T> get_row(std::size_t row) const;
        std::vector<T> get_col(std::size_t col) const;

    private:
        std::size_t _rows;
        std::size_t _cols;
        std::vector<T> _matrix;

        std::size_t check_rows_arg(std::size_t rows);
        std::size_t check_cols_arg(std::size_t cols);
        std::size_t check_template_arg(std::size_t size);
    };

}

template <typename T>
inline LinAlg::Matrix<T>::Matrix()
    :  _rows(0), _cols(0), _matrix(check_template_arg(0))
{
}

template <typename T>
inline LinAlg::Matrix<T>::Matrix(std::size_t rows, std::size_t cols)
    : _rows(check_rows_arg(rows)), _cols(check_cols_arg(cols)), _matrix(check_template_arg(rows * cols))
{
}

template <typename T>
inline LinAlg::Matrix<T>::Matrix(std::size_t rows, std::size_t cols, T value)
    : _rows(check_rows_arg(rows)), _cols(check_cols_arg(cols)), _matrix(check_template_arg(rows * cols))
{
    _matrix.assign(vector_size(), value);
}

template <typename T>
inline LinAlg::Matrix<T>::Matrix(std::size_t rows, std::size_t cols, const std::vector<T>& v)
    : _rows(check_rows_arg(rows)), _cols(check_cols_arg(cols)), _matrix(check_template_arg(rows * cols))
{
    if (v.size() != _matrix.size()) { throw std::invalid_argument("invalid vector argument size"); }

    _matrix.assign(v.begin(), v.end());
}

template <typename T>
inline LinAlg::Matrix<T>::Matrix(std::initializer_list< std::initializer_list<T> > il)
    : _rows(il.size()), _cols(il.begin()->size())
{
    if (!std::is_arithmetic<T>::value) { throw std::invalid_argument("invalid Matrix template argument"); }

    for (auto i = il.begin(); i != il.end(); ++i) {
        if (_cols != i->size()) { throw std::invalid_argument("invalid nested initializer list size"); }

        _matrix.insert(_matrix.end(), i->begin(), i->end());
    }
}

template <typename T>
inline LinAlg::Matrix<T>::Matrix(Matrix&& other) noexcept
    : _rows(other._rows), _cols(other._cols), _matrix(std::move(other._matrix))
{
    other._rows = 0;
    other._cols = 0;
}

template <typename T>
inline T& LinAlg::Matrix<T>::operator() (std::size_t row, std::size_t col)
{
    return _matrix[row * _cols + col];
}

template <typename T>
inline const T& LinAlg::Matrix<T>::operator() (std::size_t row, std::size_t col) const
{
    return _matrix[row * _cols + col];
}

template <typename T>
inline LinAlg::Matrix<T>& LinAlg::Matrix<T>::operator= (Matrix<T>&& other) noexcept
{
    _rows = other._rows;
    _cols = other._cols;
    _matrix = std::move(other._matrix);

    other._rows = 0;
    other._cols = 0;

    return *this;
}

template <typename T>
inline LinAlg::Matrix<T> LinAlg::Matrix<T>::operator* (T value)
{
    LinAlg::Matrix<T> temp(*this);
    for (T& element : temp._matrix) { element *= value; }
    return temp;
}

template <typename T>
inline LinAlg::Matrix<T> LinAlg::Matrix<T>::operator/ (T value)
{
    if (value == T()) { throw std::invalid_argument("Matrix division by zero"); }
    LinAlg::Matrix<T> temp(*this);
    for (T& element : temp._matrix) { element /= value; }
    return temp;
}

template <typename T>
inline LinAlg::Matrix<T>& LinAlg::Matrix<T>::operator*= (T value)
{
    for (T& element : _matrix) { element *= value; }
    return *this;
}

template <typename T>
inline LinAlg::Matrix<T>& LinAlg::Matrix<T>::operator/= (T value)
{
    if (value == T()) { throw std::invalid_argument("Matrix division by zero"); }
    for (T& element : _matrix) { element /= value; }
    return *this;
}

template <typename T>
inline T& LinAlg::Matrix<T>::at(std::size_t row, std::size_t col)
{
    if (row < 0 || col < 0 || _rows < row || _cols < col) { throw std::out_of_range("invalid Matrix subscripts"); }
    return _matrix[row * _cols + col];
}

template <typename T>
inline const T& LinAlg::Matrix<T>::at(std::size_t row, std::size_t col) const
{
    if (row < 0 || col < 0 || _rows < row || _cols < col) { throw std::out_of_range("invalid Matrix subscripts"); }
    return _matrix[row * _cols + col];
}

template <typename T>
inline void LinAlg::Matrix<T>::set_identity()
{
    if (!isSquare()) { throw std::invalid_argument("square Matrix required"); }

    std::vector<T> identityVector(vector_size());
    for (auto i = 0; i < identityVector.size(); i += _rows + 1) {
        identityVector[i] = 1;
    }
    *this = LinAlg::Matrix<T>(_rows, _cols, identityVector);
}

template <typename T>
inline void LinAlg::Matrix<T>::set_zero()
{
    *this = LinAlg::Matrix<T>(_rows, _cols);
}

template <typename T>
inline void LinAlg::Matrix<T>::set_diag(const std::vector<T>& v)
{
    if (!isSquare()) { throw std::invalid_argument("square Matrix required"); }
    if (v.size() != _rows) { throw std::invalid_argument("invalid vector argument size"); }

    set_zero();
    for (auto i = 0, j = 0; i < _matrix.size(); i += _rows + 1, ++j) {
        _matrix[i] = v[j];
    }
}

template <typename T>
inline void LinAlg::Matrix<T>::set_diag(std::initializer_list<T> il)
{
    if (!isSquare()) { throw std::invalid_argument("square Matrix required"); }
    if (il.size() != _rows) { throw std::invalid_argument("invalid initializer list argument size"); }

    set_zero();
    auto element = il.begin();
    for (auto i = 0; i < _matrix.size(); i += _rows + 1, ++element) {
        _matrix[i] = *element;
    }
}

template <typename T>
inline void LinAlg::Matrix<T>::set_row(T value, std::size_t row)
{
    if (row < 0 || row >= _rows) { throw std::out_of_range("invalid Matrix row subscript"); }

    for (auto i = row * _cols; i < (row + 1) * _cols; ++i) {
        _matrix[i] = value;
    }
}

template <typename T>
inline void LinAlg::Matrix<T>::set_row(const std::vector<T>& v, std::size_t row)
{
    if (v.size() != _cols) { throw std::invalid_argument("invalid vector argument size"); }
    if (row < 0 || row >= _rows) { throw std::out_of_range("invalid Matrix row subscript"); }

    for (std::size_t i = row * _cols, j = 0; j < _cols; ++i, ++j) {
        _matrix[i] = v[j];
    }
}

template <typename T>
inline void LinAlg::Matrix<T>::set_row(std::initializer_list<T> il, std::size_t row)
{
    if (il.size() != _cols) { throw std::invalid_argument("invalid initializer list argument size"); }
    if (row < 0 || row >= _rows) { throw std::out_of_range("invalid Matrix row subscript"); }

    auto element = il.begin();
    for (auto i = row * _cols; i < (row + 1) * _cols; ++i, ++element) {
        _matrix[i] = *element;
    }
}

template <typename T>
inline void LinAlg::Matrix<T>::set_col(T value, std::size_t col)
{
    if (col < 0 || col >= _cols) { throw std::out_of_range("invalid Matrix column subscript"); }

    for (auto i = col; i < (_rows - 1) * _cols + col + 1; i += _cols) {
        _matrix[i] = value;
    }
}

template <typename T>
inline void LinAlg::Matrix<T>::set_col(const std::vector<T>& v, std::size_t col)
{
    if (v.size() != _rows) { throw std::invalid_argument("invalid vector argument size"); }
    if (col < 0 || col >= _cols) { throw std::out_of_range("invalid Matrix column subscript"); }

    for (std::size_t i = col, j = 0; j < _rows; i += _cols, ++j) {
        _matrix[i] = v[j];
    }
}

template <typename T>
inline void LinAlg::Matrix<T>::set_col(std::initializer_list<T> il, std::size_t col)
{
    if (il.size() != _rows) { throw std::invalid_argument("invalid initializer list argument size"); }
    if (col < 0 || col >= _cols) { throw std::out_of_range("invalid Matrix column subscript"); }
    
    auto element = il.begin();
    for (auto i = col; i < (_rows - 1) * _cols + col + 1; i += _cols, ++element) {
        _matrix[i] = *element;
    }
}

template <typename T>
inline std::vector<T> LinAlg::Matrix<T>::get_row(std::size_t row) const
{
    if (row < 0 || row >= _rows) { throw std::out_of_range("invalid Matrix row subscript"); }

    std::vector<T> rowVector(_cols);
    for (std::size_t i = row * _cols, j = 0; j < _cols; ++i, ++j) {
        rowVector[j] = _matrix[i];
    }
    return rowVector;
}

template <typename T>
inline std::vector<T> LinAlg::Matrix<T>::get_col(std::size_t col) const
{
    if (col < 0 || col >= _cols) { throw std::out_of_range("invalid Matrix column subscript"); }

    std::vector<T> colVector(_rows);
    for (std::size_t i = col, j = 0; j < _rows; i += _cols, ++j) {
        colVector[j] = _matrix[i];
    }
    return colVector;
}

template <typename T>
inline std::size_t LinAlg::Matrix<T>::check_rows_arg(std::size_t rows)
{
    if (rows < max_rows()) { 
        return rows; 
    } else { 
        throw std::invalid_argument("invalid Matrix rows argument");
    }
}

template <typename T>
inline std::size_t LinAlg::Matrix<T>::check_cols_arg(std::size_t cols)
{
    if (_rows != 0) {
        if (cols < max_cols() && cols > 0) {
            return cols; 
        } else { 
            throw std::invalid_argument("invalid Matrix cols argument");
        }
    } else if (cols == 0) {
        return cols;
    } else {
        throw std::invalid_argument("invalid Matrix cols argument");
    }
}

template <typename T>
inline std::size_t LinAlg::Matrix<T>::check_template_arg(std::size_t size)
{
    if (std::is_arithmetic<T>::value && !std::is_const<T>::value) {
        return size;
    } else {
        throw std::invalid_argument("invalid Matrix template argument");
    }
}

#endif // MATRIX_HPP

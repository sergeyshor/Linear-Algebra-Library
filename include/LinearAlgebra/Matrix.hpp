#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>
#include <exception>
#include <initializer_list>
#include <type_traits>
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
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept; 

        std::size_t rows() const { return _rows; }
        std::size_t cols() const { return _cols; }

    private:
        std::size_t _rows;
        std::size_t _cols;
        std::vector<T> _matrix;
    };

}

template <typename T>
LinAlg::Matrix<T>::Matrix()
    : _rows(0), _cols(0),
    _matrix(std::is_arithmetic<T>::value ? 0 : throw std::invalid_argument("invalid Matrix template argument"))
{
}

template <typename T>
LinAlg::Matrix<T>::Matrix(std::size_t rows, std::size_t cols)
    : _rows(rows), _cols(cols),
    _matrix(std::is_arithmetic<T>::value ? rows * cols : throw std::invalid_argument("invalid Matrix template argument"))
{
}

template <typename T>
LinAlg::Matrix<T>::Matrix(std::size_t rows, std::size_t cols, T value)
    : _rows(rows), _cols(cols),
    _matrix(std::is_arithmetic<T>::value ? rows * cols : throw std::invalid_argument("invalid Matrix template argument"))
{
    _matrix.assign(rows * cols, value);
}

template <typename T>
LinAlg::Matrix<T>::Matrix(std::size_t rows, std::size_t cols, const std::vector<T>& v)
    : _rows(rows), _cols(cols), 
    _matrix(std::is_arithmetic<T>::value ? rows * cols : throw std::invalid_argument("invalid Matrix template argument"))
{
    if (v.size() != _matrix.size()) { throw std::length_error("invalid vector argument size"); }

    _matrix.assign(v.begin(), v.end());
}

template <typename T>
LinAlg::Matrix<T>::Matrix(std::initializer_list< std::initializer_list<T> > il)
    : _rows(il.size()), _cols(il.begin()->size())
{
    if (!std::is_arithmetic<T>::value) { throw std::invalid_argument("invalid Matrix template argument"); }

    for (auto i = il.begin(); i != il.end(); ++i) {
        if (_cols != i->size()) { throw std::length_error("invalid nested initializer list size"); }

        _matrix.insert(_matrix.end(), i->begin(), i->end());
    }
}

template <typename T>
LinAlg::Matrix<T>::Matrix(const Matrix& other)
    : _rows(other._rows), _cols(other._cols), _matrix(other._matrix)
{
}

template <typename T>
LinAlg::Matrix<T>::Matrix(Matrix&& other) noexcept
    : _rows(other._rows), _cols(other._cols), _matrix(std::move(other._matrix))
{
    other._rows = 0;
    other._cols = 0;
}

#endif // MATRIX_HPP

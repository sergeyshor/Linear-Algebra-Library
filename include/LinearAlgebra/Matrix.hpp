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

        Matrix<T>& operator= (const Matrix<T>& other) = default;
        Matrix<T>& operator= (Matrix<T>&& other) noexcept;

        std::size_t rows() const { return _rows; }
        std::size_t cols() const { return _cols; }

    private:
        std::size_t _rows;
        std::size_t _cols;
        std::vector<T> _matrix;
    };

}

template <typename T>
inline LinAlg::Matrix<T>::Matrix()
    : _rows(0), _cols(0),
    _matrix(std::is_arithmetic<T>::value ? 0 : throw std::invalid_argument("invalid Matrix template argument"))
{
}

template <typename T>
inline LinAlg::Matrix<T>::Matrix(std::size_t rows, std::size_t cols)
    : _rows(rows), _cols(cols),
    _matrix(std::is_arithmetic<T>::value ? rows * cols : throw std::invalid_argument("invalid Matrix template argument"))
{
}

template <typename T>
inline LinAlg::Matrix<T>::Matrix(std::size_t rows, std::size_t cols, T value)
    : _rows(rows), _cols(cols),
    _matrix(std::is_arithmetic<T>::value ? rows * cols : throw std::invalid_argument("invalid Matrix template argument"))
{
    _matrix.assign(rows * cols, value);
}

template <typename T>
inline LinAlg::Matrix<T>::Matrix(std::size_t rows, std::size_t cols, const std::vector<T>& v)
    : _rows(rows), _cols(cols), 
    _matrix(std::is_arithmetic<T>::value ? rows * cols : throw std::invalid_argument("invalid Matrix template argument"))
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
inline LinAlg::Matrix<T>& LinAlg::Matrix<T>::operator= (Matrix<T>&& other) noexcept
{
    _rows = other._rows;
    _cols = other._cols;
    _matrix = std::move(other._matrix);

    other._rows = 0;
    other._cols = 0;

    return *this;
}

#endif // MATRIX_HPP

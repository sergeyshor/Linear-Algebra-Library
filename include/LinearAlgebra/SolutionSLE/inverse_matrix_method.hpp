#ifndef INVERSE_MATRIX_METHOD_HPP
#define INVERSE_MATRIX_METHOD_HPP

#include "../Matrix.hpp"

namespace LinAlg 
{
    template <typename T>
    inline Matrix<T> inverse_matrix_method(const Matrix<T>& lhs, const Matrix<T>& rhs)
    {
        Matrix<T> A(lhs);
        Matrix<T> B(rhs);
        Matrix<T> X(A.inverse() * B);
        return X;
    }

}

#endif // INVERSE_MATRIX_METHOD_HPP

#ifndef INVERSE_MATRIX_METHOD_HPP
#define INVERSE_MATRIX_METHOD_HPP

#include "../Matrix.hpp"

namespace LinAlg 
{
    template <typename T>
    LinAlg::Matrix<T> inverse_matrix_method(const LinAlg::Matrix<T>& lhs, const LinAlg::Matrix<T>& rhs)
    {
        LinAlg::Matrix<T> A(lhs);
        LinAlg::Matrix<T> B(rhs);
        LinAlg::Matrix<T> X(A.inverse() * B);
        return X;
    }

}

#endif // INVERSE_MATRIX_METHOD_HPP

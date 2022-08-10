#ifndef GAUSSIAN_ELIMINATION_HPP
#define GAUSSIAN_ELIMINATION_HPP

#include "../Matrix.hpp"

namespace LinAlg 
{
    template <typename T>
    inline Matrix<T> gaussian_elimination(const Matrix<T>& lhs, const Matrix<T>& rhs)
    {
        T rank, extendedRank;

        LinAlg::Matrix<T> A(lhs);
        rank = A.rank();

        LinAlg::Matrix<T> B(rhs);

        A.join(B);
        extendedRank = A.rank();

        if (rank != extendedRank) { throw std::runtime_error("system of linear equations is inconsistent"); }
        if (rank == extendedRank && rank < A.rows()) { throw std::runtime_error("system of linear equations has infinite solutions"); }

        A = A.row_echelon();
        LinAlg::Matrix<T> X = A.back_sub();
        return X;
    }

}

#endif // GAUSSIAN_ELIMINATION_HPP

#include <gtest/gtest.h>
#include <LinearAlgebra.hpp>

TEST(LinearAlgebraTest, DefaultConstructor)
{
    // DIFFERENT TYPES MATRIX DEFAULT CONSTRUCTOR TEST
    LinAlg::Matrix<int> intMatrix;
    EXPECT_EQ(intMatrix.rows(), 0);
    EXPECT_EQ(intMatrix.cols(), 0);
    EXPECT_EQ(intMatrix.vector_size(), 0);

    LinAlg::Matrix<float> floatMatrix;
    EXPECT_EQ(floatMatrix.rows(), 0);
    EXPECT_EQ(floatMatrix.cols(), 0);
    EXPECT_EQ(floatMatrix.vector_size(), 0);

    // INVALID MATRIX TEMPLATE ARGUMENTS EXCEPTION THROWING TEST
    struct StructTest
    {
        int a, b;
    };
    ASSERT_THROW(LinAlg::Matrix<StructTest> structMatrix, std::invalid_argument);

    class ClassTest
    {
        double t1, t2;
    };
    ASSERT_THROW(LinAlg::Matrix<ClassTest> classMatrix, std::invalid_argument);
}

TEST(LinearAlgebraTest, SizeConstructor)
{
    // DIFFERENT MATRIX ROWS AND COLUMNS ARGUMENTS OF CONSTRUCTOR TEST
    std::size_t sRow = 4, sColumn = 13;
    LinAlg::Matrix<double> doubleMatrix(sRow, sColumn);
    EXPECT_EQ(doubleMatrix.rows(), 4);
    EXPECT_EQ(doubleMatrix.cols(), 13);
    EXPECT_EQ(doubleMatrix.vector_size(), 4 * 13);

    int intRow1 = 1, intColumn1 = 15;
    LinAlg::Matrix<char> charMatrix(intRow1, intColumn1);
    EXPECT_EQ(charMatrix.rows(), 1);
    EXPECT_EQ(charMatrix.cols(), 15);
    EXPECT_EQ(charMatrix.vector_size(), 1 * 15);

    LinAlg::Matrix<float> floatMatrix(124, 7);
    EXPECT_EQ(floatMatrix.rows(), 124);
    EXPECT_EQ(floatMatrix.cols(), 7);
    EXPECT_EQ(floatMatrix.vector_size(), 124 * 7);

    // EITHER ROWS ARGUMENT OR COLS ARGUMENT OF CONSTRUCTOR IS NULL OR NEGATIVE (OR BOTH NEGATIVE) TEST
    ASSERT_THROW(LinAlg::Matrix<int> intMatrix(-18, 5), std::invalid_argument);
    ASSERT_THROW(LinAlg::Matrix<int> intMatrix(135, -1), std::invalid_argument);
    ASSERT_THROW(LinAlg::Matrix<int> intMatrix(-31, -15), std::invalid_argument);
    ASSERT_THROW(LinAlg::Matrix<int> intMatrix(0, 153), std::invalid_argument);
    ASSERT_THROW(LinAlg::Matrix<int> intMatrix(641, 0), std::invalid_argument);

    // ROWS ARGUMENT AND COLS ARGUMENT BOTH ARE NULL TEST 
    LinAlg::Matrix<bool> boolMatrix(0, 0);
    EXPECT_EQ(boolMatrix.rows(), 0);
    EXPECT_EQ(boolMatrix.cols(), 0);
    EXPECT_EQ(boolMatrix.vector_size(), 0);
}

TEST(LinearAlgebraTest, ValueConstructor)
{
    // DIFFERENT VALUE ARGUMENTS OF CONSTRUCTOR TEST
    double doubleValue = 1.514;
    LinAlg::Matrix<double> doubleMatrix(21, 53, doubleValue);
    EXPECT_DOUBLE_EQ(doubleMatrix(4, 6), 1.514);
    EXPECT_DOUBLE_EQ(doubleMatrix(19, 17), 1.514);
    EXPECT_DOUBLE_EQ(doubleMatrix(20, 52), 1.514);

    int intValue = 134;
    LinAlg::Matrix<int> intMatrix(51, 1, intValue);
    EXPECT_EQ(intMatrix(4, 0), 134);
    EXPECT_EQ(intMatrix(10, 0), 134);

    LinAlg::Matrix<long> longMatrix(1, 12, 69171);
    EXPECT_EQ(longMatrix(0, 7), 69171);
    EXPECT_EQ(longMatrix(0, 0), 69171);
}

TEST(LinearAlgebraTest, VectorConstructor)
{
    // DIFFERENT VECTOR ARGUMENTS OF CONSTRUCTOR TEST
    std::vector<int> intVector{ 1, 2, 4, 5, 6, 7 };
    LinAlg::Matrix<int> intMatrix1(3, 2, intVector);
    EXPECT_EQ(intMatrix1.rows(), 3);
    EXPECT_EQ(intMatrix1.cols(), 2);
    EXPECT_EQ(intMatrix1.vector_size(), 3 * 2);
    EXPECT_EQ(intMatrix1(0, 0), 1);
    EXPECT_EQ(intMatrix1(2, 0), 6);
    EXPECT_EQ(intMatrix1(1, 1), 5);

    LinAlg::Matrix<int> intMatrix2(1, 6, intVector);
    EXPECT_EQ(intMatrix2.rows(), 1);
    EXPECT_EQ(intMatrix2.cols(), 6);
    EXPECT_EQ(intMatrix2.vector_size(), 1 * 6);
    EXPECT_EQ(intMatrix2(0, 0), 1);
    EXPECT_EQ(intMatrix2(0, 2), 4);
    EXPECT_EQ(intMatrix2(0, 5), 7);

    std::vector<double> doubleVector{ 1.9, 2.246, 14.1145, 12.13, 464.635, 531.01, 952.0, 10.7935, 101.3 };
    LinAlg::Matrix<double> doubleMatrix(3, 3, doubleVector);
    EXPECT_EQ(doubleMatrix.rows(), 3);
    EXPECT_EQ(doubleMatrix.cols(), 3);
    EXPECT_EQ(doubleMatrix.vector_size(), 3 * 3);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 0), 1.9);
    EXPECT_DOUBLE_EQ(doubleMatrix(2, 1), 10.7935);
    EXPECT_DOUBLE_EQ(doubleMatrix(2, 2), 101.3);
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 0), 12.13);

    // DIFFERENT VECTOR ARGUMENT OF CONSTRUCTOR SIZE AND MATRIX VECTOR SIZE TEST
    std::vector<float> floatVector{ 1.1, 4.5, 1.4 };
    ASSERT_THROW(LinAlg::Matrix<float> floatMatrix(1, 4, floatVector), std::invalid_argument);

    std::vector<long long> longlongVector{ 10101, 2423, 3223, 90742, 58023 };
    ASSERT_THROW(LinAlg::Matrix<long long> longlongMatrix(134, 2, longlongVector), std::invalid_argument);

    std::vector<long> longVector{ 3252, 972, 29123 };
    ASSERT_THROW(LinAlg::Matrix<long> longMatrix(1, 2, longVector), std::invalid_argument);
}

TEST(LinearAlgebraTest, InitializerListConstructor)
{
    // DIFFERENT INITIALIZER LIST ARGUMENTS OF CONSTRUCTOR TEST
    LinAlg::Matrix<int> intMatrix({ {52, 23, 98}, {-1, 2, -4} });
    EXPECT_EQ(intMatrix.rows(), 2);
    EXPECT_EQ(intMatrix.cols(), 3);
    EXPECT_EQ(intMatrix.vector_size(), 2 * 3);
    EXPECT_EQ(intMatrix(0, 0), 52);
    EXPECT_EQ(intMatrix(0, 2), 98);
    EXPECT_EQ(intMatrix(1, 0), -1);
    EXPECT_EQ(intMatrix(1, 1), 2);

    LinAlg::Matrix<double> doubleMatrix = { { 16.64, 124.0 }, { -1.42 , 24.11 } };
    EXPECT_EQ(doubleMatrix.rows(), 2);
    EXPECT_EQ(doubleMatrix.cols(), 2);
    EXPECT_EQ(doubleMatrix.vector_size(), 2 * 2);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 0), 16.64);
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 1), 24.11);
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 0), -1.42);

    LinAlg::Matrix<float> floatMatrix{ { 4.14 }, { 11.0 }, { -1.03 }, { 43.2 } };
    EXPECT_EQ(floatMatrix.rows(), 4);
    EXPECT_EQ(floatMatrix.cols(), 1);
    EXPECT_EQ(floatMatrix.vector_size(), 4 * 1);
    EXPECT_FLOAT_EQ(floatMatrix(0, 0), 4.14);
    EXPECT_FLOAT_EQ(floatMatrix(2, 0), -1.03);

    // DIFFERENT NESTED INITIALIZER LIST SIZES TEST
    ASSERT_THROW(LinAlg::Matrix<long> longMatrix({ { 405315 }, { 8531, 53235 }, { -5322 }, { 7523 } }), std::invalid_argument);
    ASSERT_THROW(LinAlg::Matrix<long long> longlongMatrix({ { 405315, 414523, }, { 8531, 53235 }, { -5322, 23553 }, { 7523 } }), std::invalid_argument);
}

TEST(LinearAlgebraTest, CopyConstructor)
{
    // DIFFERENT MATRIX ARGUMENTS OF COPY CONSTRUCTOR AND EQUALITY OF TWO MATRICES TEST
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
    LinAlg::Matrix<int> intMatrix2(intMatrix1);

    EXPECT_EQ(intMatrix1.rows(), intMatrix2.rows());
    EXPECT_EQ(intMatrix1.cols(), intMatrix2.cols());
    EXPECT_EQ(intMatrix1.vector_size(), intMatrix2.vector_size());
    for(std::size_t i = 0; i < intMatrix2.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix2.cols(); ++j) {
            EXPECT_EQ(intMatrix1(i, j), intMatrix2(i, j));
        }
    }

    LinAlg::Matrix<int> intMatrix3;
    LinAlg::Matrix<int> intMatrix4(intMatrix3);

    EXPECT_EQ(intMatrix3.rows(), intMatrix4.rows());
    EXPECT_EQ(intMatrix3.cols(), intMatrix4.cols());
    EXPECT_EQ(intMatrix3.vector_size(), intMatrix4.vector_size());

    LinAlg::Matrix<int> intMatrix5(4, 5);
    LinAlg::Matrix<int> intMatrix6(intMatrix5);

    EXPECT_EQ(intMatrix5.rows(), intMatrix6.rows());
    EXPECT_EQ(intMatrix5.cols(), intMatrix6.cols());
    EXPECT_EQ(intMatrix5.vector_size(), intMatrix6.vector_size());
    for(std::size_t i = 0; i < intMatrix6.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix6.cols(); ++j) {
            EXPECT_EQ(intMatrix5(i, j), intMatrix6(i, j));
        }
    }

    LinAlg::Matrix<int> intMatrix7(4, 5, 1);
    LinAlg::Matrix<int> intMatrix8(intMatrix7);

    EXPECT_EQ(intMatrix7.rows(), intMatrix8.rows());
    EXPECT_EQ(intMatrix7.cols(), intMatrix8.cols());
    EXPECT_EQ(intMatrix7.vector_size(), intMatrix8.vector_size());
    for(std::size_t i = 0; i < intMatrix8.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix8.cols(); ++j) {
            EXPECT_EQ(intMatrix7(i, j), intMatrix8(i, j));
        }
    }

    std::vector<int> intVector = { 1, 2, 3, 4, 5, 6 };
    LinAlg::Matrix<int> intMatrix9(3, 2, intVector);
    LinAlg::Matrix<int> intMatrix10(intMatrix9);

    EXPECT_EQ(intMatrix9.rows(), intMatrix10.rows());
    EXPECT_EQ(intMatrix9.cols(), intMatrix10.cols());
    EXPECT_EQ(intMatrix9.vector_size(), intMatrix10.vector_size());
    for(std::size_t i = 0; i < intMatrix10.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix10.cols(); ++j) {
            EXPECT_EQ(intMatrix9(i, j), intMatrix10(i, j));
        }
    }
}

TEST(LinearAlgebraTest, MoveConstructor)
{
    // DIFFERENT MATRIX ARGUMENTS OF MOVE CONSTRUCTOR, EMPTINESS OF OLD MATRIX OBJECT
    // AND FORMER RESOURCES OF OLD MATRIX AND RESOURCES OF NEW MATRIX TEST
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
    LinAlg::Matrix<int> intTempMatrix1(intMatrix1);
    LinAlg::Matrix<int> intMatrix2(std::move(intMatrix1));

    EXPECT_EQ(intMatrix2.rows(), 3);
    EXPECT_EQ(intMatrix2.cols(), 2);
    EXPECT_EQ(intMatrix2.vector_size(), 3 * 2);
    EXPECT_EQ(intMatrix1.rows(), 0);
    EXPECT_EQ(intMatrix1.cols(), 0);
    EXPECT_EQ(intMatrix1.vector_size(), 0);
    for(std::size_t i = 0; i < intMatrix2.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix2.cols(); ++j) {
            EXPECT_EQ(intTempMatrix1(i, j), intMatrix2(i, j));
        }
    }

    LinAlg::Matrix<int> intMatrix3;
    LinAlg::Matrix<int> intMatrix4(std::move(intMatrix3));

    EXPECT_EQ(intMatrix4.rows(), 0);
    EXPECT_EQ(intMatrix4.cols(), 0);
    EXPECT_EQ(intMatrix4.vector_size(), 0);
    EXPECT_EQ(intMatrix3.rows(), 0);
    EXPECT_EQ(intMatrix3.cols(), 0);
    EXPECT_EQ(intMatrix3.vector_size(), 0);

    LinAlg::Matrix<int> intMatrix5(4, 5);
    LinAlg::Matrix<int> intTempMatrix5(intMatrix5);
    LinAlg::Matrix<int> intMatrix6(std::move(intMatrix5));

    EXPECT_EQ(intMatrix6.rows(), 4);
    EXPECT_EQ(intMatrix6.cols(), 5);
    EXPECT_EQ(intMatrix6.vector_size(), 4 * 5);
    EXPECT_EQ(intMatrix5.rows(), 0);
    EXPECT_EQ(intMatrix5.cols(), 0);
    EXPECT_EQ(intMatrix5.vector_size(), 0);
    for(std::size_t i = 0; i < intMatrix6.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix6.cols(); ++j) {
            EXPECT_EQ(intTempMatrix5(i, j), intMatrix6(i, j));
        }
    }

    LinAlg::Matrix<int> intMatrix7(4, 5, 1);
    LinAlg::Matrix<int> intTempMatrix7(intMatrix7);
    LinAlg::Matrix<int> intMatrix8(std::move(intMatrix7));

    EXPECT_EQ(intMatrix8.rows(), 4);
    EXPECT_EQ(intMatrix8.cols(), 5);
    EXPECT_EQ(intMatrix8.vector_size(), 4 * 5);
    EXPECT_EQ(intMatrix7.rows(), 0);
    EXPECT_EQ(intMatrix7.cols(), 0);
    EXPECT_EQ(intMatrix7.vector_size(), 0);
    for(std::size_t i = 0; i < intMatrix8.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix8.cols(); ++j) {
            EXPECT_EQ(intTempMatrix7(i, j), intMatrix8(i, j));
        }
    }

    std::vector<int> intVector = { 1, 2, 3, 4, 5, 6 };
    LinAlg::Matrix<int> intMatrix9(3, 2, intVector);
    LinAlg::Matrix<int> intTempMatrix9(intMatrix9);
    LinAlg::Matrix<int> intMatrix10(std::move(intMatrix9));

    EXPECT_EQ(intMatrix10.rows(), 3);
    EXPECT_EQ(intMatrix10.cols(), 2);
    EXPECT_EQ(intMatrix10.vector_size(), 3 * 2);
    EXPECT_EQ(intMatrix9.rows(), 0);
    EXPECT_EQ(intMatrix9.cols(), 0);
    EXPECT_EQ(intMatrix9.vector_size(), 0);
    for(std::size_t i = 0; i < intMatrix10.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix10.cols(); ++j) {
            EXPECT_EQ(intTempMatrix9(i, j), intMatrix10(i, j));
        }
    }
}

TEST(LinearAlgebraTest, CopyAssignment)
{
    // DIFFERENT MATRIX ARGUMENTS OF COPY ASSIGNMENT OPERATOR AND EQUALITY OF TWO MATRICES TEST
    LinAlg::Matrix<int> intMatrix1 = { { 32, -2, 0, 1 }, { 4, 12, 5, 3 }, { 3, 4, 52, 3 }, { -4, 5, -27, 6 } };
    LinAlg::Matrix<int> intMatrix2;
    intMatrix2 = intMatrix1;

    EXPECT_EQ(intMatrix1.rows(), intMatrix2.rows());
    EXPECT_EQ(intMatrix1.cols(), intMatrix2.cols());
    EXPECT_EQ(intMatrix1.vector_size(), intMatrix2.vector_size());
    for(std::size_t i = 0; i < intMatrix2.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix2.cols(); ++j) {
            EXPECT_EQ(intMatrix1(i, j), intMatrix2(i, j));
        }
    }

    LinAlg::Matrix<int> intMatrix3;
    LinAlg::Matrix<int> intMatrix4(1, 2);
    intMatrix4 = intMatrix3;

    EXPECT_EQ(intMatrix3.rows(), intMatrix4.rows());
    EXPECT_EQ(intMatrix3.cols(), intMatrix4.cols());
    EXPECT_EQ(intMatrix3.vector_size(), intMatrix4.vector_size());

    LinAlg::Matrix<int> intMatrix5(4, 5);
    LinAlg::Matrix<int> intMatrix6;
    intMatrix6 = intMatrix5;

    EXPECT_EQ(intMatrix5.rows(), intMatrix6.rows());
    EXPECT_EQ(intMatrix5.cols(), intMatrix6.cols());
    EXPECT_EQ(intMatrix5.vector_size(), intMatrix6.vector_size());
    for(std::size_t i = 0; i < intMatrix6.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix6.cols(); ++j) {
            EXPECT_EQ(intMatrix5(i, j), intMatrix6(i, j));
        }
    }

    LinAlg::Matrix<int> intMatrix7(4, 5, 1);
    LinAlg::Matrix<int> intMatrix8;
    intMatrix8 = intMatrix7;

    EXPECT_EQ(intMatrix7.rows(), intMatrix8.rows());
    EXPECT_EQ(intMatrix7.cols(), intMatrix8.cols());
    EXPECT_EQ(intMatrix7.vector_size(), intMatrix8.vector_size());
    for(std::size_t i = 0; i < intMatrix8.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix8.cols(); ++j) {
            EXPECT_EQ(intMatrix7(i, j), intMatrix8(i, j));
        }
    }

    std::vector<int> intVector = { 1, 2, 3, 4, 5, 6 };
    LinAlg::Matrix<int> intMatrix9(3, 2, intVector);
    LinAlg::Matrix<int> intMatrix10;
    intMatrix10 = intMatrix9;

    EXPECT_EQ(intMatrix9.rows(), intMatrix10.rows());
    EXPECT_EQ(intMatrix9.cols(), intMatrix10.cols());
    EXPECT_EQ(intMatrix9.vector_size(), intMatrix10.vector_size());
    for(std::size_t i = 0; i < intMatrix10.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix10.cols(); ++j) {
            EXPECT_EQ(intMatrix9(i, j), intMatrix10(i, j));
        }
    }

    // SELF-ASSIGNMENT WITH COPY ASSIGNMENT OPERATOR TEST
    LinAlg::Matrix<int> intTempMatrix1(intMatrix1);
    intMatrix1 = intMatrix1;

    EXPECT_EQ(intTempMatrix1.rows(), intMatrix1.rows());
    EXPECT_EQ(intTempMatrix1.cols(), intMatrix1.cols());
    EXPECT_EQ(intTempMatrix1.vector_size(), intMatrix1.vector_size());
    for(std::size_t i = 0; i < intMatrix1.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix1.cols(); ++j) {
            EXPECT_EQ(intTempMatrix1(i, j), intMatrix1(i, j));
        }
    }

    LinAlg::Matrix<int> intTempMatrix3(intMatrix3);
    intMatrix3 = intMatrix3;

    EXPECT_EQ(intTempMatrix3.rows(), intMatrix3.rows());
    EXPECT_EQ(intTempMatrix3.cols(), intMatrix3.cols());
    EXPECT_EQ(intTempMatrix3.vector_size(), intMatrix3.vector_size());
    for(std::size_t i = 0; i < intMatrix3.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix3.cols(); ++j) {
            EXPECT_EQ(intTempMatrix3(i, j), intMatrix3(i, j));
        }
    }

    LinAlg::Matrix<int> intTempMatrix5(intMatrix5);
    intMatrix5 = intMatrix5;

    EXPECT_EQ(intTempMatrix5.rows(), intMatrix5.rows());
    EXPECT_EQ(intTempMatrix5.cols(), intMatrix5.cols());
    EXPECT_EQ(intTempMatrix5.vector_size(), intMatrix5.vector_size());
    for(std::size_t i = 0; i < intMatrix5.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix5.cols(); ++j) {
            EXPECT_EQ(intTempMatrix5(i, j), intMatrix5(i, j));
        }
    }

    LinAlg::Matrix<int> intTempMatrix7(intMatrix7);
    intMatrix7 = intMatrix7;

    EXPECT_EQ(intTempMatrix7.rows(), intMatrix7.rows());
    EXPECT_EQ(intTempMatrix7.cols(), intMatrix7.cols());
    EXPECT_EQ(intTempMatrix7.vector_size(), intMatrix7.vector_size());
    for(std::size_t i = 0; i < intMatrix7.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix7.cols(); ++j) {
            EXPECT_EQ(intTempMatrix7(i, j), intMatrix7(i, j));
        }
    }

    LinAlg::Matrix<int> intTempMatrix9(intMatrix9);
    intMatrix9 = intMatrix9;

    EXPECT_EQ(intTempMatrix9.rows(), intMatrix9.rows());
    EXPECT_EQ(intTempMatrix9.cols(), intMatrix9.cols());
    EXPECT_EQ(intTempMatrix9.vector_size(), intMatrix9.vector_size());
    for(std::size_t i = 0; i < intMatrix9.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix9.cols(); ++j) {
            EXPECT_EQ(intTempMatrix9(i, j), intMatrix9(i, j));
        }
    }
}

TEST(LinearAlgebraTest, MoveAssignment)
{
    // DIFFERENT MATRIX ARGUMENTS OF MOVE ASSIGNMENT OPERATOR, EMPTINESS OF OLD MATRIX OBJECT
    // AND FORMER RESOURCES OF OLD MATRIX AND RESOURCES OF NEW MATRIX TEST
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
    LinAlg::Matrix<int> intTempMatrix1(intMatrix1);
    LinAlg::Matrix<int> intMatrix2;
    intMatrix2 = std::move(intMatrix1);

    EXPECT_EQ(intMatrix2.rows(), 3);
    EXPECT_EQ(intMatrix2.cols(), 2);
    EXPECT_EQ(intMatrix2.vector_size(), 3 * 2);
    EXPECT_EQ(intMatrix1.rows(), 0);
    EXPECT_EQ(intMatrix1.cols(), 0);
    EXPECT_EQ(intMatrix1.vector_size(), 0);
    for(std::size_t i = 0; i < intMatrix2.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix2.cols(); ++j) {
            EXPECT_EQ(intTempMatrix1(i, j), intMatrix2(i, j));
        }
    }

    LinAlg::Matrix<int> intMatrix3;
    LinAlg::Matrix<int> intMatrix4(1, 4);
    intMatrix4 = std::move(intMatrix3);

    EXPECT_EQ(intMatrix4.rows(), 0);
    EXPECT_EQ(intMatrix4.cols(), 0);
    EXPECT_EQ(intMatrix4.vector_size(), 0);
    EXPECT_EQ(intMatrix3.rows(), 0);
    EXPECT_EQ(intMatrix3.cols(), 0);
    EXPECT_EQ(intMatrix3.vector_size(), 0);

    LinAlg::Matrix<int> intMatrix5(4, 5);
    LinAlg::Matrix<int> intTempMatrix5(intMatrix5);
    LinAlg::Matrix<int> intMatrix6;
    intMatrix6 = std::move(intMatrix5);

    EXPECT_EQ(intMatrix6.rows(), 4);
    EXPECT_EQ(intMatrix6.cols(), 5);
    EXPECT_EQ(intMatrix6.vector_size(), 4 * 5);
    EXPECT_EQ(intMatrix5.rows(), 0);
    EXPECT_EQ(intMatrix5.cols(), 0);
    EXPECT_EQ(intMatrix5.vector_size(), 0);
    for(std::size_t i = 0; i < intMatrix6.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix6.cols(); ++j) {
            EXPECT_EQ(intTempMatrix5(i, j), intMatrix6(i, j));
        }
    }

    LinAlg::Matrix<int> intMatrix7(4, 5, 1);
    LinAlg::Matrix<int> intTempMatrix7(intMatrix7);
    LinAlg::Matrix<int> intMatrix8;
    intMatrix8 = std::move(intMatrix7);

    EXPECT_EQ(intMatrix8.rows(), 4);
    EXPECT_EQ(intMatrix8.cols(), 5);
    EXPECT_EQ(intMatrix8.vector_size(), 4 * 5);
    EXPECT_EQ(intMatrix7.rows(), 0);
    EXPECT_EQ(intMatrix7.cols(), 0);
    EXPECT_EQ(intMatrix7.vector_size(), 0);
    for(std::size_t i = 0; i < intMatrix8.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix8.cols(); ++j) {
            EXPECT_EQ(intTempMatrix7(i, j), intMatrix8(i, j));
        }
    }

    std::vector<int> intVector = { 1, 2, 3, 4, 5, 6 };
    LinAlg::Matrix<int> intMatrix9(3, 2, intVector);
    LinAlg::Matrix<int> intTempMatrix9(intMatrix9);
    LinAlg::Matrix<int> intMatrix10;
    intMatrix10 = std::move(intMatrix9);

    EXPECT_EQ(intMatrix10.rows(), 3);
    EXPECT_EQ(intMatrix10.cols(), 2);
    EXPECT_EQ(intMatrix10.vector_size(), 3 * 2);
    EXPECT_EQ(intMatrix9.rows(), 0);
    EXPECT_EQ(intMatrix9.cols(), 0);
    EXPECT_EQ(intMatrix9.vector_size(), 0);
    for(std::size_t i = 0; i < intMatrix10.rows(); ++i) {
        for (std::size_t j = 0; j < intMatrix10.cols(); ++j) {
            EXPECT_EQ(intTempMatrix9(i, j), intMatrix10(i, j));
        }
    }
}

TEST(LinearAlgebraTest, MethodAt)
{
    // AT METHOD MATRIX ELEMENTS ACCESS TEST
    LinAlg::Matrix<int> intMatrix = { { -1, 27, 13, 4 }, { 68, -5, 10, 11 }, { 100, 41, 2, -12 }, { -16, 0, -1, 102 } };
    EXPECT_EQ(intMatrix.at(1, 3), 11);
    EXPECT_EQ(intMatrix.at(0, 0), -1);
    EXPECT_EQ(intMatrix.at(2, 0), 100);

    // EXCEPTION THROWING WHEN INDICES ARE OUT OF RANGE TEST 
    ASSERT_THROW(intMatrix.at(5, 0), std::out_of_range);
    ASSERT_THROW(intMatrix.at(3, -1), std::out_of_range);
    ASSERT_THROW(intMatrix.at(18, 12), std::out_of_range);

    // AT METHOD ASSIGNMENT TEST
    intMatrix.at(3, 1) = 19;
    EXPECT_EQ(intMatrix.at(3, 1), 19);

    int intValue1 = 311;
    intMatrix.at(2, 2) = intValue1;
    EXPECT_EQ(intMatrix.at(2, 2), 311);

    // ASSIGNMENT EXCEPTION THROWING WHEN INDICES ARE OUT OF RANGE TEST
    int intValue2 = -4;
    ASSERT_THROW(intMatrix.at(5, 3) = intValue2, std::out_of_range);
}

TEST(LinearAlgebraTest, OperatorMultiplicationValue)
{
    // NEGATIVE NUMBER TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
    int intValue = -4;
    intMatrix = intMatrix * intValue;
    EXPECT_EQ(intMatrix(2, 1), -40);
    EXPECT_EQ(intMatrix(0, 3), -16);
    EXPECT_EQ(intMatrix(3, 2), -60);

    // POSITIVE NUMBER TEST
    LinAlg::Matrix<double> doubleMatrix = { { 0.42, 32.1}, { 44.112, 4.0 }, { 34.52, 1.245 } };
    LinAlg::Matrix<double> resultMatrix;
    double doubleValue = 2.0;
    resultMatrix = doubleMatrix * doubleValue;
    EXPECT_DOUBLE_EQ(resultMatrix(1, 1), 8.0);
    EXPECT_DOUBLE_EQ(resultMatrix(0, 1), 64.2);
    EXPECT_DOUBLE_EQ(resultMatrix(2, 0), 69.04);

    // NULL TEST
    LinAlg::Matrix<float> floatMatrix = { { 1.1, 42.0, 4.24 }, { 7.5, 2.275, 1.124 } };
    float floatValue = 0;
    floatMatrix = floatMatrix * floatValue;
    EXPECT_FLOAT_EQ(floatMatrix(1, 0), 0);
    EXPECT_FLOAT_EQ(floatMatrix(1, 2), 0);
    EXPECT_FLOAT_EQ(floatMatrix(0, 0), 0);
}

TEST(LinearAlgebraTest, OperatorDivisionValue)
{
    // POSITIVE NUMBER TEST
    LinAlg::Matrix<int> intMatrix = { { 2, 22, 13, 4 }, { 5, 2, 14, 8 }, { 52, 4, 72, 16 } };
    LinAlg::Matrix<int> resultMatrix = { {1}, {2}, {3}, {4} };
    int intValue = 2;
    resultMatrix = intMatrix / intValue;
    EXPECT_EQ(resultMatrix(1, 0), 2);
    EXPECT_EQ(resultMatrix(0, 2), 6);
    EXPECT_EQ(resultMatrix(2, 3), 8);

    // NEGATIVE NUMBER TEST
    LinAlg::Matrix<double> doubleMatrix = { { 0.51, 9.25, 0.21 }, { -0.25, 27.125, 1.03 } };
    double doubleValue = -0.5;
    doubleMatrix = doubleMatrix / doubleValue;
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 1), -54.25);
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 0), 0.5);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 2), -0.42);

    // NULL TEST
    LinAlg::Matrix<float> floatMatrix = { { 1.37, 5.071 }, { 2.25, 31.0 }, { 15.12, 0.34 } };
    float floatValue = 0;
    ASSERT_THROW(floatMatrix = floatMatrix / floatValue, std::invalid_argument);
}

TEST(LinearAlgebraTest, OperatorMultiplicationAssignmentValue)
{
    // POSITIVE NUMBER TEST
    LinAlg::Matrix<int> intMatrix = { { -27, 105, 53, -41 }, { 79, 72, -126, 79 }, { 112, -8, 64, 84 } };
    int intValue = 3;
    intMatrix *= intValue;
    EXPECT_EQ(intMatrix(0, 1), 315);
    EXPECT_EQ(intMatrix(2, 1), -24);
    EXPECT_EQ(intMatrix(1, 3), 237);

    // NEGATIVE NUMBER TEST
    LinAlg::Matrix<double> doubleMatrix = { { 3.54, 4.03, -1.3 }, { 1.14, 25.4, 64.34 } };
    double doubleValue = -1.5;
    doubleMatrix *= doubleValue;
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 1), -38.1);
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 0), -1.71);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 2), 1.95);

    // NULL TEST
    LinAlg::Matrix<float> floatMatrix = { { 21.14, 17.125 }, { 7.24, 0.13 } };
    float floatValue = 0;
    floatMatrix *= floatValue;
    EXPECT_FLOAT_EQ(floatMatrix(1, 0), 0);
    EXPECT_FLOAT_EQ(floatMatrix(0, 1), 0);
    EXPECT_FLOAT_EQ(floatMatrix(0, 0), 0);
}

TEST(LinearAlgebraTest, OperatorDivisionAssignmentValue)
{
    // POSITIVE NUMBER TEST
    LinAlg::Matrix<int> intMatrix = { { 2, 4, 132, 53 }, { -10, 17, 108, 9 }, { 0, 10, -14, 6 } };
    int intValue = 2;
    intMatrix /= intValue;
    EXPECT_EQ(intMatrix(0, 2), 66);
    EXPECT_EQ(intMatrix(1, 1), 8);
    EXPECT_EQ(intMatrix(1, 0), -5);

    // NEGATIVE NUMBER TEST
    LinAlg::Matrix<double> doubleMatrix = { { 0.15, 2.25 }, { -9.2, 11.3 } };
    double doubleValue = -0.2;
    doubleMatrix /= doubleValue;
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 1), -56.5);
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 0), 46);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 1), -11.25);

    // NULL TEST
    LinAlg::Matrix<float> floatMatrix = { { 7.5, 0.523, 10.125 }, { 52.1, -0.41, 53.04 }, { -1.2, 0.375, 1.04 } };
    float floatValue = 0;
    ASSERT_THROW(floatMatrix /= floatValue, std::invalid_argument);
}

TEST(LinearAlgebraTest, MethodSetIdentity)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix(5, 5, 3);
    intMatrix.set_identity();
    EXPECT_EQ(intMatrix(1, 1), 1);
    EXPECT_EQ(intMatrix(0, 3), 0);
    EXPECT_EQ(intMatrix(4, 4), 1);
    EXPECT_EQ(intMatrix(2, 0), 0);

    LinAlg::Matrix<double> doubleMatrix = { { 1.12, 8.5, 9.0 }, { 0.31, 7.26, 15.11 }, { -0.103, 5.26, 16.125 } };
    doubleMatrix.set_identity();
    EXPECT_EQ(doubleMatrix(2, 2), 1);
    EXPECT_EQ(doubleMatrix(0, 1), 0);
    EXPECT_EQ(doubleMatrix(1, 1), 1);
    EXPECT_EQ(doubleMatrix(2, 0), 0);

    // NOT SQUARE MATRIX TEST
    LinAlg::Matrix<float> floatMatrix = { { 1.131, -0.6, 2.7 }, { 12.3, 103.23, 9.5 } };
    ASSERT_THROW(floatMatrix.set_identity(), std::invalid_argument);
}

TEST(LinearAlgebraTest, MethodSetZero)
{
    // SETTING MATRIX ELEMENTS TO ZERO TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    intMatrix.set_zero();
    EXPECT_EQ(intMatrix(1, 2), 0);
    EXPECT_EQ(intMatrix(0, 0), 0);

    LinAlg::Matrix<double> doubleMatrix = { { 0.1, 8.0, 1.3, 5.25, 6.39 }, { 7.5, 2.275, 19.11, 0.27, 1.1 } };
    doubleMatrix.set_zero();
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 2), 0);
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 4), 0);
}

TEST(LinearAlgebraTest, MethodSetDiagVector)
{
    // DIFFERENT MATRICES TEST
    std::vector<int> intDiagVector = { 10, 11, 12 };
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    intMatrix.set_diag(intDiagVector);
    EXPECT_EQ(intMatrix(1, 1), 11);
    EXPECT_EQ(intMatrix(0, 1), 0);
    EXPECT_EQ(intMatrix(2, 2), 12);
    EXPECT_EQ(intMatrix(2, 0), 0);

    std::vector<double> doubleDiagVector = { 0.1, -1.125, 0, 7.36 };
    LinAlg::Matrix<double> doubleMatrix = { { -35.0, 6.123, 4.11, 6.27 }, { 0.42, 5.3, 0.01, 41.2 }, { 94.32, 0.37, -7.125, 3.1 }, { 3.375, 4.9, -4.3, 9.37 } };
    doubleMatrix.set_diag(doubleDiagVector);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 0), 0.1);
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 2), 0);
    EXPECT_DOUBLE_EQ(doubleMatrix(2, 2), 0);
    EXPECT_DOUBLE_EQ(doubleMatrix(1, 1), -1.125);
    EXPECT_DOUBLE_EQ(doubleMatrix(3, 0), 0);

    // NOT SQUARE MATRIX TEST
    std::vector<long long> longlongDiagVector = { 123, 56, 322 };
    LinAlg::Matrix<long long> longlongMatrix = { { 31, 452, 53 }, { 27, 531, 624 } };
    ASSERT_THROW(longlongMatrix.set_diag(longlongDiagVector), std::invalid_argument);

    // INVALID VECTOR ARGUMENT OF CONSTRUCTOR SIZE TEST
    std::vector<float> floatDiagVector = { 0.1, 4.2, 42.3 };
    LinAlg::Matrix<float> floatMatrix = { { 10.0, 4.12 }, { 3.5, 1.125 } };
    ASSERT_THROW(floatMatrix.set_diag(floatDiagVector), std::invalid_argument);

    std::vector<long> longDiagVector = { 3517, -2108, 62 };
    LinAlg::Matrix<long> longMatrix = { { 623, 431, 35, 531 }, { 53, 90, 1, 352 }, { 74, 513, 89, 6531 }, { 421, 4, 51, 920 } };
    ASSERT_THROW(longMatrix.set_diag(longDiagVector), std::invalid_argument);
}

TEST(LinearAlgebraTest, MethodSetDiagInitializerList)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix = { { 7, 53, 21, -34 }, { 90, 3, 5, -2 }, { 145, 42, 6, 0 }, { 12, 52, 37, 54 } };
    intMatrix.set_diag({ 51, 13, 4, 2 });
    EXPECT_EQ(intMatrix(1, 1), 13);
    EXPECT_EQ(intMatrix(0, 2), 0);
    EXPECT_EQ(intMatrix(3, 3), 2);
    EXPECT_EQ(intMatrix(1, 0), 0);

    LinAlg::Matrix<float> floatMatrix = { { 14.4, -1.6 }, { 12.15, 6.2 } };
    floatMatrix.set_diag({ -2.7, 5.1 });
    EXPECT_FLOAT_EQ(floatMatrix(0, 0), -2.7);
    EXPECT_FLOAT_EQ(floatMatrix(0, 1), 0);
    EXPECT_FLOAT_EQ(floatMatrix(1, 1), 5.1);
    EXPECT_FLOAT_EQ(floatMatrix(1, 0), 0);

    // NOT SQUARE MATRIX TEST
    LinAlg::Matrix<long> longMatrix = { { 663, 471, 631, 0 }, { -46, 55, 1, 804 }, { 412, 27, -2, 513 } };
    ASSERT_THROW(longMatrix.set_diag({ 607, 26, -1 }), std::invalid_argument);

    // INVALID INITIALIZER LIST ARGUMENT OF CONSTRUCTOR SIZE TEST
    LinAlg::Matrix<long long> longlongMatrix = { { -3, 296, 14 }, { 62, 0, 1 }, { -51, 72, 4 } };
    ASSERT_THROW(longlongMatrix.set_diag({ 923, -215 }), std::invalid_argument);

    LinAlg::Matrix<double> doubleMatrix = { { 1.4, 0.13, -5.27, 0.6 }, { 5.2, 0, 23.78, 6.41 }, { 6.1, 0.217, 7.73, 0.18 }, { 56.0, 9.5, 67.7, 7.24 } };
    ASSERT_THROW(doubleMatrix.set_diag({ 3.07, 86.98, 62.4, 0.51, 3.23 }), std::invalid_argument);
}

TEST(LinearAlgebraTest, MethodSetRowValue)
{
    // METHOD SET ROW DIFFERENT VALUES TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
    intMatrix.set_row(-17, 2);
    EXPECT_EQ(intMatrix(2, 0), -17);
    EXPECT_EQ(intMatrix(2, 1), -17);
    EXPECT_EQ(intMatrix(2, 2), -17);

    double doubleValue = 0.485;
    LinAlg::Matrix<double> doubleMatrix = { { 53.1, 15.59 }, { 7.4, 62.3 }, { 0.464, 2.88 } };
    doubleMatrix.set_row(doubleValue, 0);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 0), 0.485);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 1), 0.485);

    // OUT OF RANGE ROW INDEX TEST
    long long longlongValue = 75148;
    LinAlg::Matrix<long long> longlongMatrix = { { 41, 0, -261 }, { 0, 58, 1023 }, { 64, 915, -32 } };
    ASSERT_THROW(longlongMatrix.set_row(longlongValue, 3), std::out_of_range);

    short shortValue = -15;
    LinAlg::Matrix<short> shortMatrix = { { 12, -18, 51, 5 }, { 14, 119, 41, 6 } };
    ASSERT_THROW(shortMatrix.set_row(shortValue, -1), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSetRowVector)
{
    // METHOD SET ROW DIFFERENT VALUES TEST
    std::vector<int> intVector = { 27, 0, 14 };
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
    intMatrix.set_row(intVector, 2);
    EXPECT_EQ(intMatrix(2, 0), 27);
    EXPECT_EQ(intMatrix(2, 1), 0);
    EXPECT_EQ(intMatrix(2, 2), 14);

    std::vector<double> doubleVector = { -5.31, 26.5 };
    LinAlg::Matrix<double> doubleMatrix = { { 4.17, 8.125 }, { 7.214, 9.52 } };
    doubleMatrix.set_row(doubleVector, 0);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 0), -5.31);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 1), 26.5);

    // INVALID VECTOR ARGUMENT OF CONSTRUCTOR SIZE TEST
    std::vector<long> longVector = { 41, 326, 214 };
    LinAlg::Matrix<long> longMatrix = { { 1, 532, 6, -15 }, { -81, 0, 643, 956 }, { 2, 57, -231, 45 }, { 35, -18, 46, 10 } };
    ASSERT_THROW(longMatrix.set_row(longVector, 1), std::invalid_argument);

    std::vector<float> floatVector = { -0.237, 5.2 };
    LinAlg::Matrix<float> floatMatrix = { { -1.571 }, { 0.91 }, { -4.532 }, { 1.0 }, { 4.12 } };
    ASSERT_THROW(floatMatrix.set_row(floatVector, 3), std::invalid_argument);

    // OUT OF RANGE ROW INDEX TEST
    std::vector<long long> longlongVector = { 41, 26, 514 };
    LinAlg::Matrix<long long> longlongMatrix = { { 91, -7, 36 }, { 23, -10, 76 }, { 82, 166, -15 } };
    ASSERT_THROW(longlongMatrix.set_row(longlongVector, 3), std::out_of_range);

    std::vector<short> shortVector = { 13, 52 };
    LinAlg::Matrix<short> shortMatrix = { { 41, 37 }, { -4, 89 } };
    ASSERT_THROW(shortMatrix.set_row(shortVector, -2), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSetRowInitializerList)
{
    // METHOD SET ROW DIFFERENT VALUES TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
    intMatrix.set_row({ 1, -5, 12 }, 2);
    EXPECT_EQ(intMatrix(2, 0), 1);
    EXPECT_EQ(intMatrix(2, 1), -5);
    EXPECT_EQ(intMatrix(2, 2), 12);

    LinAlg::Matrix<double> doubleMatrix = { { 41.2, -1.316 }, { 2.49, 0.22 } };
    doubleMatrix.set_row({ 9.12, 75.3 }, 0);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 0), 9.12);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 1), 75.3);

    // INVALID INITIALIZER LIST ARGUMENT OF CONSTRUCTOR SIZE TEST
    LinAlg::Matrix<long> longMatrix = { { -6, 89, 1, 22 }, { 13, -17, 0, 52 }, { 1071, 12, 41, 3 }, { 12, -10, 2310, 515 } };
    ASSERT_THROW(longMatrix.set_row({ 50, 19, -5 }, 1), std::invalid_argument);

    LinAlg::Matrix<float> floatMatrix = { { 3.41 }, { -1.35 }, { 2.0 }, { 11.34 }, { 9.8 } };
    ASSERT_THROW(floatMatrix.set_row({ -1.0, 0.45 }, 3), std::invalid_argument);

    // OUT OF RANGE ROW INDEX TEST
    LinAlg::Matrix<long long> longlongMatrix = { { 5, -7, 12 }, { 10, 217, 14 }, { 86, -5, 5237 } };
    ASSERT_THROW(longlongMatrix.set_row({ 53, 110, 42 }, -1), std::out_of_range);

    LinAlg::Matrix<short> shortMatrix = { { 51, -19 }, { 0, 78 } };
    ASSERT_THROW(shortMatrix.set_row({ 37, 242 }, 2), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSetColValue)
{
    // METHOD SET COL DIFFERENT VALUES TEST
    int intValue = -64;
    LinAlg::Matrix<int> intMatrix = { { 42, 101, 0 }, { 13, 59, -7 }, { 91, 8, 24 }, { 89, 14, -384 } };
    intMatrix.set_col(intValue, 2);
    EXPECT_EQ(intMatrix(0, 2), -64);
    EXPECT_EQ(intMatrix(1, 2), -64);
    EXPECT_EQ(intMatrix(2, 2), -64);
    EXPECT_EQ(intMatrix(3, 2), -64);

    LinAlg::Matrix<float> floatMatrix = { { 0.61, 7.5, -3.12, 85.3 }, { 9.21, 0, -17.4, 12.65 }, { 4.156, 62.3, 0.1, -2.88 } };
    floatMatrix.set_col(-0.34, 1);
    EXPECT_FLOAT_EQ(floatMatrix(0, 1), -0.34);
    EXPECT_FLOAT_EQ(floatMatrix(1, 1), -0.34);
    EXPECT_FLOAT_EQ(floatMatrix(2, 1), -0.34);

    // OUT OF RANGE COL INDEX TEST
    short shortValue = 4;
    LinAlg::Matrix<short> shortMatrix = { { 61, -33 }, { 0, 15 }, { 67, 128 }, { -237, 8 } };
    ASSERT_THROW(shortMatrix.set_col(shortValue, -5), std::out_of_range);

    long long longlongValue = 8953;
    LinAlg::Matrix<long long> longlongMatrix = { { 628, 532, -7163, 0 }, { 4901, 12, 575, -104 } };
    ASSERT_THROW(longlongMatrix.set_col(longlongValue, 4), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSetColVector)
{
    // METHOD SET COL DIFFERENT VALUES TEST
    std::vector<int> intVector = { -76, 88, 39, 6 };
    LinAlg::Matrix<int> intMatrix = { { 91, -48, -19 }, { 64, 59, -3 }, { 21, 89, 14 }, { 31, 47, -26 } };
    intMatrix.set_col(intVector, 2);
    EXPECT_EQ(intMatrix(0, 2), -76);
    EXPECT_EQ(intMatrix(1, 2), 88);
    EXPECT_EQ(intMatrix(2, 2), 39);
    EXPECT_EQ(intMatrix(3, 2), 6);

    std::vector<float> floatVector = { 4.82, 9.53, -15.7 };
    LinAlg::Matrix<float> floatMatrix = { { -0.5, 1.2, 0.12, 2.26 }, { 0, 5.32, 33.41, 1.5 }, { 6.23, 36.4, 1.53, 0 } };
    floatMatrix.set_col(floatVector, 1);
    EXPECT_FLOAT_EQ(floatMatrix(0, 1), 4.82);
    EXPECT_FLOAT_EQ(floatMatrix(1, 1), 9.53);
    EXPECT_FLOAT_EQ(floatMatrix(2, 1), -15.7);

    // INVALID VECTOR ARGUMENT OF CONSTRUCTOR SIZE TEST
    std::vector<long> longVector = { 423, 164, 6, 13 };
    LinAlg::Matrix<long> longMatrix = { { 2, -5 }, { 341, 0 } };
    ASSERT_THROW(longMatrix.set_col(longVector, 0), std::invalid_argument);

    std::vector<double> doubleVector = { 10.121, 5.5 };
    LinAlg::Matrix<double> doubleMatrix = { { 45.17, 3.1, -0.38 }, { 1.14, 125.8, 9.51 }, { -0.4, 124.0, 7.42 } };
    ASSERT_THROW(doubleMatrix.set_col(doubleVector, 1), std::invalid_argument);

    // OUT OF RANGE COL INDEX TEST
    std::vector<short> shortVector = { 51, 27, -1, 23 };
    LinAlg::Matrix<short> shortMatrix = { { 624, 81 }, { -56, 7 }, { 24, 73 }, { 112, -3 } };
    ASSERT_THROW(shortMatrix.set_col(shortVector, -1), std::out_of_range);

    std::vector<long long> longlongVector = { -35, 824 };
    LinAlg::Matrix<long long> longlongMatrix = { { 4, 21, 9463, -551 }, { 631, -3, 285, -147 } };
    ASSERT_THROW(longlongMatrix.set_col(longlongVector, 4), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSetColInitializerList)
{
    // METHOD SET COL DIFFERENT VALUES TEST
    LinAlg::Matrix<int> intMatrix = { { 1, -8, 0 }, { 13, 57, 9 }, { 101, 6, 352 }, { 36, 68, -4 } };
    intMatrix.set_col({ 16, 5, 12, -7 }, 2);
    EXPECT_EQ(intMatrix(0, 2), 16);
    EXPECT_EQ(intMatrix(1, 2), 5);
    EXPECT_EQ(intMatrix(2, 2), 12);
    EXPECT_EQ(intMatrix(3, 2), -7);

    LinAlg::Matrix<float> floatMatrix = { { 0.13, -4.5, 12.11, 68.3 }, { -9.6, 0.415, 10.93, 4.792 }, { 6.634, 0.46, 0, 4.53 } };
    floatMatrix.set_col({ 19.5, 7.04, -6.0 }, 1);
    EXPECT_FLOAT_EQ(floatMatrix(0, 1), 19.5);
    EXPECT_FLOAT_EQ(floatMatrix(1, 1), 7.04);
    EXPECT_FLOAT_EQ(floatMatrix(2, 1), -6.0);

    // INVALID INITIALIZER LIST ARGUMENT OF CONSTRUCTOR SIZE TEST
    LinAlg::Matrix<long> longMatrix = { { 141, -822 }, { 2307, -75 } };
    ASSERT_THROW(longMatrix.set_col({ 0, 42, 705, 12 }, 0), std::invalid_argument);

    LinAlg::Matrix<double> doubleMatrix = { { 0.14, 5.6, -17.1 }, { 0, 2.13, 5.2 }, { 0.79, 31.0, 5.734 } };
    ASSERT_THROW(doubleMatrix.set_col({ -13.642, 2.4 }, 1), std::invalid_argument);

    // // OUT OF RANGE COL INDEX TEST
    LinAlg::Matrix<short> shortMatrix = { { 17, 41 }, { -124, 63 }, { 103, 57 }, { 81, 0 } };
    ASSERT_THROW(shortMatrix.set_col({ 100, 37, 12, -4 }, -2), std::out_of_range);

    LinAlg::Matrix<long long> longlongMatrix = { { 62, 101, 2037, -4325 }, { 2, 0, -151, 222 } };
    ASSERT_THROW(longlongMatrix.set_col({ 6318, 263 }, 4), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodGetRow)
{
    // METHOD GET ROW DIFFERENT VALUES TEST
    LinAlg::Matrix<int> intMatrix = { { 8, 10 }, { -5, 3 } };
    std::vector<int> intVector = intMatrix.get_row(0);
    for(std::size_t i = 0; i < intVector.size(); ++i) { 
        EXPECT_EQ(intVector[i], intMatrix(0, i));
    }

    LinAlg::Matrix<double> doubleMatrix = { { 0.14, -2.1, 17.135 }, { 1.5, 3.8, 9.27 }, { 51.2, 6.4, 7.05 } };
    std::vector<double> doubleVector = doubleMatrix.get_row(1);
    for(std::size_t i = 0; i < doubleVector.size(); ++i) { 
        EXPECT_DOUBLE_EQ(doubleVector[i], doubleMatrix(1, i));
    }

    // OUT OF RANGE ROW INDEX TEST
    LinAlg::Matrix<float> floatMatrix = { { 0.634 }, { 9.21 }, { 15.17 }, { 14.08 } };
    ASSERT_THROW(std::vector<float> floatVector = floatMatrix.get_row(-1), std::out_of_range);

    LinAlg::Matrix<short> shortMatrix = { { 1, -5 }, { 91, 58 }, { 53, 0 } };
    ASSERT_THROW(std::vector<short> shortVector = shortMatrix.get_row(3), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodGetCol)
{
    // METHOD GET COL DIFFERENT VALUES TEST
    LinAlg::Matrix<float> floatMatrix = { { 7.14, 2.88 }, { -0.12, 3.53 }, { 10.47, 3.8 }, { -0.1, 6.2 }, { 3.61, 14.2 } };
    std::vector<float> floatVector = floatMatrix.get_col(0);
    for(std::size_t i = 0; i < floatVector.size(); ++i) { 
        EXPECT_FLOAT_EQ(floatVector[i], floatMatrix(i, 0));
    }

    LinAlg::Matrix<int> intMatrix = { { 75, 0, 421 }, { -107, 135, 9 } };
    std::vector<int> intVector = intMatrix.get_col(1);
    for(std::size_t i = 0; i < intVector.size(); ++i) { 
        EXPECT_EQ(intVector[i], intMatrix(i, 1));
    }

    // OUT OF RANGE COL INDEX TEST
    LinAlg::Matrix<double> doubleMatrix = { { 1.42, 7.011 }, { 3.51, 67.25 }, { 81.13, -1.94 }, { 0.12, -8.159 } };
    ASSERT_THROW(std::vector<double> doubleVector = doubleMatrix.get_col(-2), std::out_of_range);

    LinAlg::Matrix<long> longMatrix = { { 1183, 0, 12 }, { 5913, -671, 530 }, { 758, 2417, -100 } };
    ASSERT_THROW(std::vector<long> longVector = longMatrix.get_col(3), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodTranspose)
{
    // DIFFERENT MATRICES TRANSPOSE METHOD TEST
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2, 3 }, { 4, 5, 6 } };
    LinAlg::Matrix<int> intMatrix2(intMatrix1);
    intMatrix1.transpose();
    for (auto i = 0; i < intMatrix1.rows(); ++i) {
        for (auto j = 0; j < intMatrix1.cols(); ++j) {
            EXPECT_EQ(intMatrix1(i, j), intMatrix2(j, i));
        }
    }

    LinAlg::Matrix<double> doubleMatrix1 = { { 1.5, -5.375, 6.24 }, { 8.8, 0.21, 7.2 }, { -0.27, 19.48, 1.4 } };
    LinAlg::Matrix<double> doubleMatrix2(doubleMatrix1);
    doubleMatrix1.transpose();
    for (auto i = 0; i < doubleMatrix1.rows(); ++i) {
        for (auto j = 0; j < doubleMatrix1.cols(); ++j) {
            EXPECT_EQ(doubleMatrix1(i, j), doubleMatrix2(j, i));
        }
    }
}

TEST(LinearAlgebraTest, MethodMinor)
{
    // DIFFERENT MATRICES MINOR METHOD TEST
    LinAlg::Matrix<int> intMatrix1 = { { -1, 914, 13 }, { 47, -12, 0 }, { 151, 10, 8 } };
    LinAlg::Matrix<int> checkIntMatrix1 = { { -1, 13 }, { 151, 8 } };
    LinAlg::Matrix<int> minorIntMatrix1 = intMatrix1.minor(1, 1);
    for (auto i = 0; i < minorIntMatrix1.rows(); ++i) {
        for (auto j = 0; j < minorIntMatrix1.cols(); ++j) {
            EXPECT_EQ(checkIntMatrix1.at(i, j), minorIntMatrix1.at(i, j));
        }
    }

    LinAlg::Matrix<double> doubleMatrix = { { -0.4, 23.27, 19.5 }, { 4.3, -5.29, 1.36 }, { 8.58, 1.033, 32.5 } };
    LinAlg::Matrix<double> checkDoubleMatrix = { { -0.4, 23.27 }, { 8.58, 1.033 } };
    LinAlg::Matrix<double> minorDoubleMatrix = doubleMatrix.minor(1, 2);
    for (auto i = 0; i < minorDoubleMatrix.rows(); ++i) {
        for (auto j = 0; j < minorDoubleMatrix.cols(); ++j) {
            EXPECT_DOUBLE_EQ(checkDoubleMatrix.at(i, j), minorDoubleMatrix.at(i, j));
        }
    }

    LinAlg::Matrix<long> longMatrix = { { 5078, 352, 458, 15 }, { -253, 264, 62, 1667 }, { 643, 100, 5753, -274 }, { 6, 544, 12, -4 } };
    LinAlg::Matrix<long> checkLongMatrix = { { 5078, 352, 15 }, { -253, 264, 1667 }, { 643, 100, -274 } };
    LinAlg::Matrix<long> minorLongMatrix = longMatrix.minor(3, 2);
    for (auto i = 0; i < minorLongMatrix.rows(); ++i) {
        for (auto j = 0; j < minorLongMatrix.cols(); ++j) {
            EXPECT_EQ(checkLongMatrix.at(i, j), minorLongMatrix.at(i, j));
        }
    }

    // INVALID ROW ARGUMENT TEST
    LinAlg::Matrix<int> intMatrix2 = { { 1, 2, 3 }, { 6, 5, 4 }, { 7, 9, 8 } };
    ASSERT_THROW(intMatrix2.minor(7, 1), std::out_of_range);

    // INVALID COL ARGUMENT TEST
    LinAlg::Matrix<float> floatMatrix1 = { { 1.9, -3.25 }, { 12.37, 8.88 } };
    ASSERT_THROW(floatMatrix1.minor(0, 4), std::out_of_range);

    // INVALID ROW AND COL ARGUMENTS TEST
    LinAlg::Matrix<short> shortMatrix = { { 25, 54, 1, -5 }, { 0, 52, 63, 27 }, { -5, 64, 16, 10 }, { 200, 74, 13, 50 } };
    ASSERT_THROW(shortMatrix.minor(6, 5), std::out_of_range);

    // NOT SQUARE MATRIX TEST
    LinAlg::Matrix<int> intMatrix3 = { { -3, 42, 1 }, { 4, 81, -9 } };
    ASSERT_THROW(intMatrix3.minor(0, 0), std::invalid_argument);
}

TEST(LinearAlgebraTest, MethodDeterminant)
{
    // ZERO-ORDER MATRIX DETERMINANT TEST
    LinAlg::Matrix<int> intMatrix0;
    EXPECT_EQ(intMatrix0.determinant(), 0);

    // FIRST-ORDER MATRIX DETERMINANT TEST
    LinAlg::Matrix<double> doubleMatrix1 = { { -1.9 } };
    EXPECT_DOUBLE_EQ(doubleMatrix1.determinant(), -1.9);

    // SECOND-ORDER MATRIX DETERMINANT TEST
    LinAlg::Matrix<int> intMatrix2 = { { -1, 2 }, { -6, 14 } };
    EXPECT_EQ(intMatrix2.determinant(), -2);

    // THIRD-ORDER MATRIX DETERMINANT TEST
    LinAlg::Matrix<int> intMatrix3 = { { -1, 43, 2 }, { 0, 51, -13 }, { 12, 5, 27 } };
    EXPECT_EQ(intMatrix3.determinant(), -9374);

    // FOURTH-ORDER MATRIX DETERMINANT TEST
    LinAlg::Matrix<int> intMatrix4 = { { 2, -4, 1, 12 }, { 11, 10, 6, 0 }, { -6, 21, 7, -1 }, { 7, 1, -8, 19 } };
    EXPECT_EQ(intMatrix4.determinant(), 45234);

    // NOT SQUARE MATRIX TEST
    LinAlg::Matrix<float> floatMatrix = { { 1.3, -14.0, 5.7 }, { 0.0, 12.79, 4.24 } };
    ASSERT_THROW(floatMatrix.determinant(), std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
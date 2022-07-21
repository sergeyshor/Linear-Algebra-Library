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

    // INVALID VECTOR ARGUMENT OF CONSTRUCTOR SIZE
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

    // INVALID INITIALIZER LIST ARGUMENT OF CONSTRUCTOR SIZE
    LinAlg::Matrix<long long> longlongMatrix = { { -3, 296, 14 }, { 62, 0, 1 }, { -51, 72, 4 } };
    ASSERT_THROW(longlongMatrix.set_diag({ 923, -215 }), std::invalid_argument);

    LinAlg::Matrix<double> doubleMatrix = { { 1.4, 0.13, -5.27, 0.6 }, { 5.2, 0, 23.78, 6.41 }, { 6.1, 0.217, 7.73, 0.18 }, { 56.0, 9.5, 67.7, 7.24 } };
    ASSERT_THROW(doubleMatrix.set_diag({ 3.07, 86.98, 62.4, 0.51, 3.23 }), std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
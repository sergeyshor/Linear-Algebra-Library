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
    EXPECT_TRUE(intMatrix1 == intMatrix2);

    LinAlg::Matrix<int> intMatrix3;
    LinAlg::Matrix<int> intMatrix4(intMatrix3);
    EXPECT_TRUE(intMatrix3 == intMatrix4);

    LinAlg::Matrix<int> intMatrix5(4, 5);
    LinAlg::Matrix<int> intMatrix6(intMatrix5);
    EXPECT_TRUE(intMatrix5 == intMatrix6);

    LinAlg::Matrix<int> intMatrix7(4, 5, 1);
    LinAlg::Matrix<int> intMatrix8(intMatrix7);
    EXPECT_TRUE(intMatrix7 == intMatrix8);

    std::vector<int> intVector = { 1, 2, 3, 4, 5, 6 };
    LinAlg::Matrix<int> intMatrix9(3, 2, intVector);
    LinAlg::Matrix<int> intMatrix10(intMatrix9);
    EXPECT_TRUE(intMatrix9 == intMatrix10);
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
    EXPECT_TRUE(intTempMatrix1 == intMatrix2);

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
    EXPECT_TRUE(intTempMatrix5 == intMatrix6);

    LinAlg::Matrix<int> intMatrix7(4, 5, 1);
    LinAlg::Matrix<int> intTempMatrix7(intMatrix7);
    LinAlg::Matrix<int> intMatrix8(std::move(intMatrix7));
    EXPECT_EQ(intMatrix8.rows(), 4);
    EXPECT_EQ(intMatrix8.cols(), 5);
    EXPECT_EQ(intMatrix8.vector_size(), 4 * 5);
    EXPECT_EQ(intMatrix7.rows(), 0);
    EXPECT_EQ(intMatrix7.cols(), 0);
    EXPECT_EQ(intMatrix7.vector_size(), 0);
    EXPECT_TRUE(intTempMatrix7 == intMatrix8);

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
    EXPECT_TRUE(intTempMatrix9 == intMatrix10);
}

TEST(LinearAlgebraTest, CopyAssignment)
{
    // DIFFERENT MATRIX ARGUMENTS OF COPY ASSIGNMENT OPERATOR AND EQUALITY OF TWO MATRICES TEST
    LinAlg::Matrix<int> intMatrix1 = { { 32, -2, 0, 1 }, { 4, 12, 5, 3 }, { 3, 4, 52, 3 }, { -4, 5, -27, 6 } };
    LinAlg::Matrix<int> intMatrix2;
    intMatrix2 = intMatrix1;
    EXPECT_TRUE(intMatrix1 == intMatrix2);

    LinAlg::Matrix<int> intMatrix3;
    LinAlg::Matrix<int> intMatrix4(1, 2);
    intMatrix4 = intMatrix3;
    EXPECT_EQ(intMatrix3.rows(), intMatrix4.rows());
    EXPECT_EQ(intMatrix3.cols(), intMatrix4.cols());
    EXPECT_EQ(intMatrix3.vector_size(), intMatrix4.vector_size());

    LinAlg::Matrix<int> intMatrix5(4, 5);
    LinAlg::Matrix<int> intMatrix6;
    intMatrix6 = intMatrix5;
    EXPECT_TRUE(intMatrix5 == intMatrix6);

    LinAlg::Matrix<int> intMatrix7(4, 5, 1);
    LinAlg::Matrix<int> intMatrix8;
    intMatrix8 = intMatrix7;
    EXPECT_TRUE(intMatrix7 == intMatrix8);

    std::vector<int> intVector = { 1, 2, 3, 4, 5, 6 };
    LinAlg::Matrix<int> intMatrix9(3, 2, intVector);
    LinAlg::Matrix<int> intMatrix10;
    intMatrix10 = intMatrix9;
    EXPECT_TRUE(intMatrix9 == intMatrix10);

    // SELF-ASSIGNMENT WITH COPY ASSIGNMENT OPERATOR TEST
    LinAlg::Matrix<int> intTempMatrix1(intMatrix1);
    intMatrix1 = intMatrix1;
    EXPECT_TRUE(intTempMatrix1 == intMatrix1);

    LinAlg::Matrix<int> intTempMatrix3(intMatrix3);
    intMatrix3 = intMatrix3;
    EXPECT_TRUE(intTempMatrix3 == intMatrix3);

    LinAlg::Matrix<int> intTempMatrix5(intMatrix5);
    intMatrix5 = intMatrix5;
    EXPECT_TRUE(intTempMatrix5 == intMatrix5);

    LinAlg::Matrix<int> intTempMatrix7(intMatrix7);
    intMatrix7 = intMatrix7;
    EXPECT_TRUE(intTempMatrix7 == intMatrix7);

    LinAlg::Matrix<int> intTempMatrix9(intMatrix9);
    intMatrix9 = intMatrix9;
    EXPECT_TRUE(intTempMatrix9 == intMatrix9);
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
    EXPECT_TRUE(intTempMatrix1 == intMatrix2);

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
    EXPECT_TRUE(intTempMatrix5 == intMatrix6);

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
    EXPECT_TRUE(intTempMatrix7 == intMatrix8);

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
    EXPECT_TRUE(intTempMatrix9 == intMatrix10);

    // SELF-ASSIGNMENT WITH MOVE ASSIGNMENT OPERATOR TEST
    intMatrix2 = std::move(intMatrix2);
    EXPECT_TRUE(intTempMatrix1 == intMatrix2);

    intMatrix3 = std::move(intMatrix3);
    EXPECT_EQ(intMatrix4.rows(), 0);
    EXPECT_EQ(intMatrix4.cols(), 0);
    EXPECT_EQ(intMatrix4.vector_size(), 0);
    EXPECT_EQ(intMatrix3.rows(), 0);
    EXPECT_EQ(intMatrix3.cols(), 0);
    EXPECT_EQ(intMatrix3.vector_size(), 0);

    intMatrix6 = std::move(intMatrix6);
    EXPECT_TRUE(intTempMatrix5 == intMatrix6);

    intMatrix8 = std::move(intMatrix8);
    EXPECT_TRUE(intTempMatrix7 == intMatrix8);

    intMatrix10 = std::move(intMatrix10);
    EXPECT_TRUE(intTempMatrix9 == intMatrix10);
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

TEST(LinearAlgebraTest, OperatorMultiplicationValueRHS)
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
    intMatrix.set_row(2, -17);
    EXPECT_EQ(intMatrix(2, 0), -17);
    EXPECT_EQ(intMatrix(2, 1), -17);
    EXPECT_EQ(intMatrix(2, 2), -17);

    double doubleValue = 0.485;
    LinAlg::Matrix<double> doubleMatrix = { { 53.1, 15.59 }, { 7.4, 62.3 }, { 0.464, 2.88 } };
    doubleMatrix.set_row(0, doubleValue);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 0), 0.485);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 1), 0.485);

    // OUT OF RANGE ROW INDEX TEST
    long long longlongValue = 75148;
    LinAlg::Matrix<long long> longlongMatrix = { { 41, 0, -261 }, { 0, 58, 1023 }, { 64, 915, -32 } };
    ASSERT_THROW(longlongMatrix.set_row(3, longlongValue), std::out_of_range);

    short shortValue = -15;
    LinAlg::Matrix<short> shortMatrix = { { 12, -18, 51, 5 }, { 14, 119, 41, 6 } };
    ASSERT_THROW(shortMatrix.set_row(-1, shortValue), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSetRowVector)
{
    // METHOD SET ROW DIFFERENT VALUES TEST
    std::vector<int> intVector = { 27, 0, 14 };
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
    intMatrix.set_row(2, intVector);
    EXPECT_EQ(intMatrix(2, 0), 27);
    EXPECT_EQ(intMatrix(2, 1), 0);
    EXPECT_EQ(intMatrix(2, 2), 14);

    std::vector<double> doubleVector = { -5.31, 26.5 };
    LinAlg::Matrix<double> doubleMatrix = { { 4.17, 8.125 }, { 7.214, 9.52 } };
    doubleMatrix.set_row(0, doubleVector);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 0), -5.31);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 1), 26.5);

    // INVALID VECTOR ARGUMENT OF CONSTRUCTOR SIZE TEST
    std::vector<long> longVector = { 41, 326, 214 };
    LinAlg::Matrix<long> longMatrix = { { 1, 532, 6, -15 }, { -81, 0, 643, 956 }, { 2, 57, -231, 45 }, { 35, -18, 46, 10 } };
    ASSERT_THROW(longMatrix.set_row(1, longVector), std::invalid_argument);

    std::vector<float> floatVector = { -0.237, 5.2 };
    LinAlg::Matrix<float> floatMatrix = { { -1.571 }, { 0.91 }, { -4.532 }, { 1.0 }, { 4.12 } };
    ASSERT_THROW(floatMatrix.set_row(3, floatVector), std::invalid_argument);

    // OUT OF RANGE ROW INDEX TEST
    std::vector<long long> longlongVector = { 41, 26, 514 };
    LinAlg::Matrix<long long> longlongMatrix = { { 91, -7, 36 }, { 23, -10, 76 }, { 82, 166, -15 } };
    ASSERT_THROW(longlongMatrix.set_row(3, longlongVector), std::out_of_range);

    std::vector<short> shortVector = { 13, 52 };
    LinAlg::Matrix<short> shortMatrix = { { 41, 37 }, { -4, 89 } };
    ASSERT_THROW(shortMatrix.set_row(-2, shortVector), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSetRowInitializerList)
{
    // METHOD SET ROW DIFFERENT VALUES TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 10, 11, 12 } };
    intMatrix.set_row(2, { 1, -5, 12 });
    EXPECT_EQ(intMatrix(2, 0), 1);
    EXPECT_EQ(intMatrix(2, 1), -5);
    EXPECT_EQ(intMatrix(2, 2), 12);

    LinAlg::Matrix<double> doubleMatrix = { { 41.2, -1.316 }, { 2.49, 0.22 } };
    doubleMatrix.set_row(0, { 9.12, 75.3 });
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 0), 9.12);
    EXPECT_DOUBLE_EQ(doubleMatrix(0, 1), 75.3);

    // INVALID INITIALIZER LIST ARGUMENT OF CONSTRUCTOR SIZE TEST
    LinAlg::Matrix<long> longMatrix = { { -6, 89, 1, 22 }, { 13, -17, 0, 52 }, { 1071, 12, 41, 3 }, { 12, -10, 2310, 515 } };
    ASSERT_THROW(longMatrix.set_row(1, { 50, 19, -5 }), std::invalid_argument);

    LinAlg::Matrix<float> floatMatrix = { { 3.41 }, { -1.35 }, { 2.0 }, { 11.34 }, { 9.8 } };
    ASSERT_THROW(floatMatrix.set_row(3, { -1.0, 0.45 }), std::invalid_argument);

    // OUT OF RANGE ROW INDEX TEST
    LinAlg::Matrix<long long> longlongMatrix = { { 5, -7, 12 }, { 10, 217, 14 }, { 86, -5, 5237 } };
    ASSERT_THROW(longlongMatrix.set_row(-1, { 53, 110, 42 }), std::out_of_range);

    LinAlg::Matrix<short> shortMatrix = { { 51, -19 }, { 0, 78 } };
    ASSERT_THROW(shortMatrix.set_row(2, { 37, 242 }), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSetColValue)
{
    // METHOD SET COL DIFFERENT VALUES TEST
    int intValue = -64;
    LinAlg::Matrix<int> intMatrix = { { 42, 101, 0 }, { 13, 59, -7 }, { 91, 8, 24 }, { 89, 14, -384 } };
    intMatrix.set_col(2, intValue);
    EXPECT_EQ(intMatrix(0, 2), -64);
    EXPECT_EQ(intMatrix(1, 2), -64);
    EXPECT_EQ(intMatrix(2, 2), -64);
    EXPECT_EQ(intMatrix(3, 2), -64);

    LinAlg::Matrix<float> floatMatrix = { { 0.61, 7.5, -3.12, 85.3 }, { 9.21, 0, -17.4, 12.65 }, { 4.156, 62.3, 0.1, -2.88 } };
    floatMatrix.set_col(1, -0.34);
    EXPECT_FLOAT_EQ(floatMatrix(0, 1), -0.34);
    EXPECT_FLOAT_EQ(floatMatrix(1, 1), -0.34);
    EXPECT_FLOAT_EQ(floatMatrix(2, 1), -0.34);

    // OUT OF RANGE COL INDEX TEST
    short shortValue = 4;
    LinAlg::Matrix<short> shortMatrix = { { 61, -33 }, { 0, 15 }, { 67, 128 }, { -237, 8 } };
    ASSERT_THROW(shortMatrix.set_col(-5, shortValue), std::out_of_range);

    long long longlongValue = 8953;
    LinAlg::Matrix<long long> longlongMatrix = { { 628, 532, -7163, 0 }, { 4901, 12, 575, -104 } };
    ASSERT_THROW(longlongMatrix.set_col(4, longlongValue), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSetColVector)
{
    // METHOD SET COL DIFFERENT VALUES TEST
    std::vector<int> intVector = { -76, 88, 39, 6 };
    LinAlg::Matrix<int> intMatrix = { { 91, -48, -19 }, { 64, 59, -3 }, { 21, 89, 14 }, { 31, 47, -26 } };
    intMatrix.set_col(2, intVector);
    EXPECT_EQ(intMatrix(0, 2), -76);
    EXPECT_EQ(intMatrix(1, 2), 88);
    EXPECT_EQ(intMatrix(2, 2), 39);
    EXPECT_EQ(intMatrix(3, 2), 6);

    std::vector<float> floatVector = { 4.82, 9.53, -15.7 };
    LinAlg::Matrix<float> floatMatrix = { { -0.5, 1.2, 0.12, 2.26 }, { 0, 5.32, 33.41, 1.5 }, { 6.23, 36.4, 1.53, 0 } };
    floatMatrix.set_col(1, floatVector);
    EXPECT_FLOAT_EQ(floatMatrix(0, 1), 4.82);
    EXPECT_FLOAT_EQ(floatMatrix(1, 1), 9.53);
    EXPECT_FLOAT_EQ(floatMatrix(2, 1), -15.7);

    // INVALID VECTOR ARGUMENT OF CONSTRUCTOR SIZE TEST
    std::vector<long> longVector = { 423, 164, 6, 13 };
    LinAlg::Matrix<long> longMatrix = { { 2, -5 }, { 341, 0 } };
    ASSERT_THROW(longMatrix.set_col(0, longVector), std::invalid_argument);

    std::vector<double> doubleVector = { 10.121, 5.5 };
    LinAlg::Matrix<double> doubleMatrix = { { 45.17, 3.1, -0.38 }, { 1.14, 125.8, 9.51 }, { -0.4, 124.0, 7.42 } };
    ASSERT_THROW(doubleMatrix.set_col(1, doubleVector), std::invalid_argument);

    // OUT OF RANGE COL INDEX TEST
    std::vector<short> shortVector = { 51, 27, -1, 23 };
    LinAlg::Matrix<short> shortMatrix = { { 624, 81 }, { -56, 7 }, { 24, 73 }, { 112, -3 } };
    ASSERT_THROW(shortMatrix.set_col(-1, shortVector), std::out_of_range);

    std::vector<long long> longlongVector = { -35, 824 };
    LinAlg::Matrix<long long> longlongMatrix = { { 4, 21, 9463, -551 }, { 631, -3, 285, -147 } };
    ASSERT_THROW(longlongMatrix.set_col(4, longlongVector), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSetColInitializerList)
{
    // METHOD SET COL DIFFERENT VALUES TEST
    LinAlg::Matrix<int> intMatrix = { { 1, -8, 0 }, { 13, 57, 9 }, { 101, 6, 352 }, { 36, 68, -4 } };
    intMatrix.set_col(2, { 16, 5, 12, -7 });
    EXPECT_EQ(intMatrix(0, 2), 16);
    EXPECT_EQ(intMatrix(1, 2), 5);
    EXPECT_EQ(intMatrix(2, 2), 12);
    EXPECT_EQ(intMatrix(3, 2), -7);

    LinAlg::Matrix<float> floatMatrix = { { 0.13, -4.5, 12.11, 68.3 }, { -9.6, 0.415, 10.93, 4.792 }, { 6.634, 0.46, 0, 4.53 } };
    floatMatrix.set_col(1, { 19.5, 7.04, -6.0 });
    EXPECT_FLOAT_EQ(floatMatrix(0, 1), 19.5);
    EXPECT_FLOAT_EQ(floatMatrix(1, 1), 7.04);
    EXPECT_FLOAT_EQ(floatMatrix(2, 1), -6.0);

    // INVALID INITIALIZER LIST ARGUMENT OF CONSTRUCTOR SIZE TEST
    LinAlg::Matrix<long> longMatrix = { { 141, -822 }, { 2307, -75 } };
    ASSERT_THROW(longMatrix.set_col(0, { 0, 42, 705, 12 }), std::invalid_argument);

    LinAlg::Matrix<double> doubleMatrix = { { 0.14, 5.6, -17.1 }, { 0, 2.13, 5.2 }, { 0.79, 31.0, 5.734 } };
    ASSERT_THROW(doubleMatrix.set_col(1, { -13.642, 2.4 }), std::invalid_argument);

    // // OUT OF RANGE COL INDEX TEST
    LinAlg::Matrix<short> shortMatrix = { { 17, 41 }, { -124, 63 }, { 103, 57 }, { 81, 0 } };
    ASSERT_THROW(shortMatrix.set_col(-2, { 100, 37, 12, -4 }), std::out_of_range);

    LinAlg::Matrix<long long> longlongMatrix = { { 62, 101, 2037, -4325 }, { 2, 0, -151, 222 } };
    ASSERT_THROW(longlongMatrix.set_col(4, { 6318, 263 }), std::out_of_range);
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
    LinAlg::Matrix<int> checkMatrix1 = { { 1, 4 }, { 2, 5 }, { 3, 6 } };
    EXPECT_TRUE(intMatrix1 == checkMatrix1);

    LinAlg::Matrix<double> doubleMatrix1 = { { 1.5, -5.375, 6.24 }, { 8.8, 0.21, 7.2 }, { -0.27, 19.48, 1.4 } };
    LinAlg::Matrix<double> doubleMatrix2(doubleMatrix1);
    doubleMatrix1.transpose();
    LinAlg::Matrix<double> checkMatrix2 = { { 1.5, 8.8, -0.27 }, { -5.375, 0.21, 19.48 }, { 6.24, 7.2, 1.4 } };
    EXPECT_TRUE(doubleMatrix1 == checkMatrix2);
}

TEST(LinearAlgebraTest, MethodMinor)
{
    // DIFFERENT MATRICES MINOR METHOD TEST
    LinAlg::Matrix<int> intMatrix1 = { { -1, 914, 13 }, { 47, -12, 0 }, { 151, 10, 8 } };
    LinAlg::Matrix<int> checkIntMatrix1 = { { -1, 13 }, { 151, 8 } };
    LinAlg::Matrix<int> minorIntMatrix1 = intMatrix1.minor(1, 1);
    EXPECT_TRUE(checkIntMatrix1 == minorIntMatrix1);

    LinAlg::Matrix<double> doubleMatrix = { { -0.4, 23.27, 19.5 }, { 4.3, -5.29, 1.36 }, { 8.58, 1.033, 32.5 } };
    LinAlg::Matrix<double> checkDoubleMatrix = { { -0.4, 23.27 }, { 8.58, 1.033 } };
    LinAlg::Matrix<double> minorDoubleMatrix = doubleMatrix.minor(1, 2);
    EXPECT_TRUE(checkDoubleMatrix == minorDoubleMatrix);

    LinAlg::Matrix<long> longMatrix = { { 5078, 352, 458, 15 }, { -253, 264, 62, 1667 }, { 643, 100, 5753, -274 }, { 6, 544, 12, -4 } };
    LinAlg::Matrix<long> checkLongMatrix = { { 5078, 352, 15 }, { -253, 264, 1667 }, { 643, 100, -274 } };
    LinAlg::Matrix<long> minorLongMatrix = longMatrix.minor(3, 2);
    EXPECT_TRUE(checkLongMatrix == minorLongMatrix);

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

TEST(LinearAlgebraTest, MethodCofactor)
{
    // DIFFERENT MATRICES COFACTOR METHOD TEST
    LinAlg::Matrix<int> intMatrix1 = { { 14, -56, -7 }, { 100, 9, 75 }, { 13, 24, 16 } };
    EXPECT_EQ(intMatrix1.cofactor(1, 1), 315);

    LinAlg::Matrix<double> doubleMatrix = { { -15.0, 5.82, 11.13 }, { 7.06, 1.009, 12.77 }, { 4.45, 21.4, 6.45 } };
    EXPECT_DOUBLE_EQ(doubleMatrix.cofactor(1, 2), 346.899);

    LinAlg::Matrix<long> longMatrix = { { 542, 1003, 236, 1753 }, { -68, 223, -1, 39 }, { 643, 100, 5753, -274 }, { 6, 15, 671, -156 } };
    LinAlg::Matrix<long> minorLongMatrix = longMatrix.minor(3, 2);
    EXPECT_EQ(longMatrix.cofactor(3, 2), 292048066);

    // INVALID ROW ARGUMENT TEST
    LinAlg::Matrix<int> intMatrix2 = { { 10, -2, 7 }, { 5, 9, 1 }, { 6, 3, 3 } };
    ASSERT_THROW(intMatrix2.cofactor(-4, 2), std::out_of_range);

    // INVALID COL ARGUMENT TEST
    LinAlg::Matrix<float> floatMatrix1 = { { -0.325, 8.27 }, { 1.431, 0 } };
    ASSERT_THROW(floatMatrix1.cofactor(0, -1), std::out_of_range);

    // INVALID ROW AND COL ARGUMENTS TEST
    LinAlg::Matrix<short> shortMatrix = { { 5, 37, 19, 3 }, { -6, 16, 44, 1 }, { 100, -4, 0, 219 }, { 35, 2, 67, -99 } };
    ASSERT_THROW(shortMatrix.cofactor(4, 4), std::out_of_range);

    // NOT SQUARE MATRIX TEST
    LinAlg::Matrix<int> intMatrix3 = { { 1, 27, 3 }, { -8, 65, 4 } };
    ASSERT_THROW(intMatrix3.cofactor(0, 1), std::invalid_argument);
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

TEST(LinearAlgebraTest, MethodAdjoint)
{
    // ZERO-ORDER MATRIX TEST
    LinAlg::Matrix<float> floatMatrix;
    LinAlg::Matrix<float> adjointFloatMatrix = floatMatrix.adjoint();
    EXPECT_EQ(floatMatrix.rows(), adjointFloatMatrix.rows());
    EXPECT_EQ(floatMatrix.cols(), adjointFloatMatrix.cols());
    EXPECT_EQ(floatMatrix.vector_size(), adjointFloatMatrix.vector_size());

    // FIRST-ORDER MATRIX TEST
    LinAlg::Matrix<double> doubleMatrix = { { -2.37 } };
    LinAlg::Matrix<double> adjointDoubleMatrix = doubleMatrix.adjoint();
    EXPECT_DOUBLE_EQ(adjointDoubleMatrix.at(0, 0), 1);

    // SECOND-ORDER MATRIX TEST
    LinAlg::Matrix<int> intMatrix1 = { { 3, 2 }, { 1, 5 } };
    LinAlg::Matrix<int> adjointIntMatrix1 = intMatrix1.adjoint();
    LinAlg::Matrix<int> checkAdjointMatrix1 = { { 5, -2 }, { -1, 3 } }; 
    EXPECT_TRUE(adjointIntMatrix1 == checkAdjointMatrix1);

    // THIRD-ORDER MATRIX TEST
    LinAlg::Matrix<short> shortMatrix = { { 1, 2, 3 }, { 0, 4, 5 }, { 1, 0, 6 } };
    LinAlg::Matrix<short> adjointShortMatrix = shortMatrix.adjoint();
    LinAlg::Matrix<short> checkAdjointMatrix2 = { { 24, -12, -2 }, { 5, 3, -5 }, { -4, 2, 4 } };
    EXPECT_TRUE(adjointShortMatrix == checkAdjointMatrix2);

    // FOURTH-ORDER MATRIX TEST
    LinAlg::Matrix<int> intMatrix2 = { { 1, 0, 0, 1 }, { 0, 2, 1, 2 }, { 2, 1, 0, 1 }, { 2, 0, 1, 4 } };
    LinAlg::Matrix<int> adjointIntMatrix2 = intMatrix2.adjoint();
    LinAlg::Matrix<int> checkAdjointMatrix3 = { { -4, -1, 2, 1 }, { 2, 1, 0, -1 }, { -16, -2, 4, 4 }, { 6, 1, -2, -1 } }; 
    EXPECT_TRUE(adjointIntMatrix2 == checkAdjointMatrix3);

    // NOT SQUARE MATRIX TEST
    LinAlg::Matrix<long> longMatrix = { { 153, 700 }, { 956, 14 }, { 81, 22 } };
    ASSERT_THROW(longMatrix.adjoint(), std::invalid_argument);
}

TEST(LinearAlgebraTest, MethodInverse)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<short> shortMatrix = { { 5, 2 }, { -7, -3 } };
    LinAlg::Matrix<short> inverseShortMatrix = shortMatrix.inverse();
    LinAlg::Matrix<short> checkInverseMatrix1 = { { 3, 2 }, { -7, -5 } };
    EXPECT_TRUE(inverseShortMatrix == checkInverseMatrix1);

    LinAlg::Matrix<float> floatMatrix = { { 1, 2, -1 }, { 2, 1, 2 }, { -1, 2, 1 } };
    LinAlg::Matrix<float> inverseFloatMatrix = floatMatrix.inverse();
    LinAlg::Matrix<float> checkInverseMatrix2 = { { 0.1875, 0.25, -0.3125 }, { 0.25, 0, 0.25 }, { -0.3125, 0.25, 0.1875 } };
    EXPECT_TRUE(inverseFloatMatrix == checkInverseMatrix2);

    LinAlg::Matrix<double> doubleMatrix = { { 1, 1, 1, 0 }, { 0, 3, 1, 2 }, { 2, 3, 1, 0 }, { 1, 0, 2, 1 } };
    LinAlg::Matrix<double> inverseDoubleMatrix = doubleMatrix.inverse();
    LinAlg::Matrix<double> checkInverseMatrix3 = { { -3, -0.5, 1.5, 1 }, { 1, 0.25, -0.25, -0.5 }, { 3, 0.25, -1.25, -0.5 }, { -3, 0, 1, 1 } };
    EXPECT_TRUE(inverseDoubleMatrix == checkInverseMatrix3);

    // NOT SQUARE MATRIX TEST
    LinAlg::Matrix<int> intMatrix = { { 51, 100, 42 }, { 739, 0, 68 } };
    ASSERT_THROW(intMatrix.inverse(), std::invalid_argument);

    // NULL DETERMINANT TEST
    LinAlg::Matrix<long> longMatrix = { { 5, 7, 8 }, { 9, 11, 12 }, { 13, 15, 16 } };
    ASSERT_THROW(longMatrix.inverse(), std::runtime_error);
}

TEST(LinearAlgebraTest, OperatorUnaryMinus)
{
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2, 3 }, { 4, 5, 6 } };
    LinAlg::Matrix<int> intMatrix2 = -intMatrix1;
    LinAlg::Matrix<int> checkMatrix1 = { { -1, -2, -3 }, { -4, -5, -6 } };
    EXPECT_TRUE(intMatrix2 == checkMatrix1);

    LinAlg::Matrix<float> floatMatrix1 = { { 0, -1.42 }, { 15.0, -8.31 } };
    LinAlg::Matrix<float> floatMatrix2 = -floatMatrix1;
    LinAlg::Matrix<float> checkMatrix2 = { { 0, 1.42 }, { -15.0, 8.31 } };
    EXPECT_TRUE(floatMatrix2 == checkMatrix2);
}

TEST(LinearAlgebraTest, OperatorAdditionMatrix)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
    LinAlg::Matrix<int> intMatrix2 = { { 17, 18, 19, 20 }, { 21, 22, 23, 24 }, { 25, 26, 27, 28 }, { 29, 30, 31, 32 } };
    LinAlg::Matrix<int> intMatrix3 = intMatrix1 + intMatrix2;
    LinAlg::Matrix<int> checkMatrix1 = { { 18, 20, 22, 24 }, { 26, 28, 30, 32 }, { 34, 36, 38, 40 }, { 42, 44, 46, 48 } };
    EXPECT_TRUE(intMatrix3 == checkMatrix1);

    LinAlg::Matrix<float> floatMatrix1 = { { 2.237, -1.2, 0.32}, { 71.85, 0, -4.9 } };
    LinAlg::Matrix<float> floatMatrix2 = { { -0.64, 15.25, 4.53 }, { 9.9, 1.01, -0.2 } };
    LinAlg::Matrix<float> floatMatrix3 = floatMatrix1 + floatMatrix2;
    LinAlg::Matrix<float> checkMatrix2 = { { 1.597, 14.05, 4.85 }, { 81.75, 1.01, -5.1 } };
    EXPECT_TRUE(floatMatrix3 == checkMatrix2);

    // INVALID MATRIX ARGUMENT SIZE
    LinAlg::Matrix<short> shortMatrix1 = { { 1, 6, -4 }, { 0, 43, 9 } };
    LinAlg::Matrix<short> shortMatrix2 = { { 58, 100 }, { 72, 11 } };
    ASSERT_THROW(shortMatrix1 + shortMatrix2, std::invalid_argument);
}

TEST(LinearAlgebraTest, OperatorSubstractionMatrix)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix1 = { { 7, -2, 1 }, { 18, 6, 51 }, { 24, 0, -5 } };
    LinAlg::Matrix<int> intMatrix2 = { { 52, -7, 9 }, { 22, 3, 14 }, { 8, 11, 0 } };
    LinAlg::Matrix<int> intMatrix3 = intMatrix1 - intMatrix2;
    LinAlg::Matrix<int> checkMatrix1 = { { -45, 5, -8 }, { -4, 3, 37 }, { 16, -11, -5 } };
    EXPECT_TRUE(intMatrix3 == checkMatrix1);

    LinAlg::Matrix<double> doubleMatrix1 = { { 1.14, 6.05, 17.08, 19.11 }, { 1.061, -0.5, 11.25, 2.3 } };
    LinAlg::Matrix<double> doubleMatrix2 = { { 0, 6.64, 3.81, 1.5 }, { 9.091, 7.42, -0.162, 21.5 } };
    LinAlg::Matrix<double> doubleMatrix3 = doubleMatrix1 - doubleMatrix2;
    LinAlg::Matrix<double> checkMatrix2 = { { 1.14, -0.59, 13.27, 17.61 }, { -8.03, -7.92, 11.412, -19.2 } };
    EXPECT_TRUE(doubleMatrix3 == checkMatrix2);

    // INVALID MATRIX ARGUMENT SIZE
    LinAlg::Matrix<short> shortMatrix1 = { { 51, 190 }, { 10, 235 } };
    LinAlg::Matrix<short> shortMatrix2 = { { 39, 88, -108, 70 }, { 200, -1, 12, 0 } };
    ASSERT_THROW(shortMatrix1 - shortMatrix2, std::invalid_argument);
}

TEST(LinearAlgebraTest, OperatorMultiplicationMatrix)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix1 = { { 17, 14 }, { 45, 72 } };
    LinAlg::Matrix<int> intMatrix2 = { { -5, 8 }, { 10, 1 } };
    LinAlg::Matrix<int> intMatrix3 = intMatrix1 * intMatrix2;
    LinAlg::Matrix<int> checkMatrix1 = { { 55, 150 }, { 495, 432 } };
    EXPECT_TRUE(intMatrix3 == checkMatrix1);

    LinAlg::Matrix<float> floatMatrix1 = { { 4.12, 14.0, 0.32 }, { 2.1, -3.05, 1.03 } };
    LinAlg::Matrix<float> floatMatrix2 = { { -10.3, 1.8 }, { 1.0, 0.4 }, { 5.9, 3.5 } };
    LinAlg::Matrix<float> floatMatrix3 = floatMatrix1 * floatMatrix2;
    LinAlg::Matrix<float> checkMatrix2 = { { -26.548, 14.136 }, { -18.603, 6.165 } };
    EXPECT_TRUE(floatMatrix3 == checkMatrix2);

    // INVALID MATRIX ARGUMENT SIZE
    LinAlg::Matrix<long> longMatrix1 = { { -14, 6, 7 }, { 53, 98, 0 } };
    LinAlg::Matrix<long> longMatrix2 = { { 1, 24, -8 }, { 31, 64, 9 } };
    ASSERT_THROW(longMatrix1 * longMatrix2, std::invalid_argument);
}

TEST(LinearAlgebraTest, OperatorDivisionMatrix)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<double> doubleMatrix1 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    LinAlg::Matrix<double> doubleMatrix2 = { { 3, 1, -1 }, { 2, -2, 0 }, { 1, 2, -1 } };
    LinAlg::Matrix<double> doubleMatrix3 = doubleMatrix1 / doubleMatrix2;
    LinAlg::Matrix<double> checkMatrix1 = { { 12, -10, -15 }, { 27, -22, -33 }, { 42, -34, -51 } };
    EXPECT_TRUE(doubleMatrix3 == checkMatrix1);

    LinAlg::Matrix<short> shortMatrix1 = { { 14, 10 }, { 27, -8 } };
    LinAlg::Matrix<short> shortMatrix2 = { { 1, 2 }, { 2, 3 } };
    LinAlg::Matrix<short> shortMatrix3 = shortMatrix1 / shortMatrix2;
    LinAlg::Matrix<short> checkMatrix2 = { { -22, 18 }, { -97, 62 } };
    EXPECT_TRUE(shortMatrix3 == checkMatrix2);

    // NOT SQUARE MATRIX
    LinAlg::Matrix<int> intMatrix1 = { { 100, 33, 45 }, { -2, 75, 1 } };
    LinAlg::Matrix<int> intMatrix2 = { { 28, 50 }, { 9, 14 }, { 42, -10 } };
    ASSERT_THROW(intMatrix1 / intMatrix2, std::invalid_argument);

    LinAlg::Matrix<int> intMatrix3 = { { 58 }, { -142 } };
    LinAlg::Matrix<int> intMatrix4 = { { 11, 46 }, { 31, 20 } };
    ASSERT_THROW(intMatrix3 / intMatrix4, std::invalid_argument);

    // NULL DETERMINANT
    LinAlg::Matrix<long> longMatrix1 = { { 51, 117, 28 }, { -5, 705, 100 }, { 0, 1670, 81 } };
    LinAlg::Matrix<long> longMatrix2 = { { 732, 261, 0 }, { 1, 16, 0 }, { -7, 10, 0 } };
    ASSERT_THROW(longMatrix1 / longMatrix2, std::runtime_error);
}

TEST(LinearAlgebraTest, OperatorAdditionAssignmentMatrix)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<double> doubleMatrix1 = { { -1.921, 53.46 }, { 0.35, 14.174 } };
    LinAlg::Matrix<double> doubleMatrix2 = { { 5.88, 0.407 }, { 2.125, 7.705 } };
    LinAlg::Matrix<double> tempDoubleMatrix = doubleMatrix1 + doubleMatrix2;
    doubleMatrix1 += doubleMatrix2;
    EXPECT_TRUE(doubleMatrix1 == tempDoubleMatrix);

    LinAlg::Matrix<int> intMatrix1 = { { 42, 10, 0 }, { 212, 68, 300 } };
    LinAlg::Matrix<int> intMatrix2 = { { 9, -16, 225 }, { 17, 24, -1 } };
    LinAlg::Matrix<int> tempIntMatrix = intMatrix1 + intMatrix2;
    intMatrix2 += intMatrix1;
    EXPECT_TRUE(intMatrix2 == tempIntMatrix);

    // INVALID MATRIX ARGUMENT SIZE
    LinAlg::Matrix<short> shortMatrix1 = { { 12, 7, 52, 100 }, { 3, 18, 27, 15 } };
    LinAlg::Matrix<short> shortMatrix2 = { { 11, -10 }, { 120, -4 } };
    ASSERT_THROW(shortMatrix1 += shortMatrix2, std::invalid_argument);
}

TEST(LinearAlgebraTest, OperatorSubstractionAssignmentMatrix)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<float> floatMatrix1 = { { 15.1, -6.75 }, { 10.125, 21.34 } };
    LinAlg::Matrix<float> floatMatrix2 = { { -5.3, 10.04 }, { 9.12, 75.32 } };
    LinAlg::Matrix<float> tempFloatMatrix = floatMatrix1 - floatMatrix2;
    floatMatrix1 -= floatMatrix2;
    EXPECT_TRUE(floatMatrix1 == tempFloatMatrix);

    LinAlg::Matrix<int> intMatrix1 = { { 0, -9, 12, 31 }, { 15, -7, 204, 16 } };
    LinAlg::Matrix<int> intMatrix2 = { { 23, -5, 10, 13 }, { 19, 311, 0, 17 } };
    LinAlg::Matrix<int> tempIntMatrix = intMatrix2 - intMatrix1;
    intMatrix2 -= intMatrix1;
    EXPECT_TRUE(intMatrix2 == tempIntMatrix);

    // INVALID MATRIX ARGUMENT SIZE
    LinAlg::Matrix<long> longMatrix1 = { { 50, 2, 951 }, { 47, -3, 100 } };
    LinAlg::Matrix<long> longMatrix2 = { { 513, -1024 }, { 245, 189 } };
    ASSERT_THROW(longMatrix1 -= longMatrix2, std::invalid_argument);
}

TEST(LinearAlgebraTest, OperatorMultiplicationAssignmentMatrix)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2 }, { 3, 4 } };
	LinAlg::Matrix<int> intMatrix2 = { { 5, 6 }, { 7, 8 } };
    LinAlg::Matrix<int> tempIntMatrix = intMatrix1 * intMatrix2;
    intMatrix1 *= intMatrix2;
    EXPECT_TRUE(intMatrix1 == tempIntMatrix);

    LinAlg::Matrix<short> shortMatrix1 = { { 16, -1, 14 }, { 12, 2, 7 } };
	LinAlg::Matrix<short> shortMatrix2 = { { 1, 9 }, { 18, 27 }, { 0, 10 } };
    LinAlg::Matrix<short> tempShortMatrix = shortMatrix1 * shortMatrix2;
    shortMatrix1 *= shortMatrix2;
    EXPECT_TRUE(shortMatrix1 == tempShortMatrix);

    // INVALID MATRIX ARGUMENT SIZE
    LinAlg::Matrix<double> doubleMatrix1 = { { 1.0, -12.14, 5.3 }, { 4.48, 0.15, 2.275 } };
    LinAlg::Matrix<double> doubleMatrix2 = { { 1.5 }, { 7.05 } };
    ASSERT_THROW(doubleMatrix1 *= doubleMatrix2, std::invalid_argument);
}

TEST(LinearAlgebraTest, OperatorDivisionAssignmentMatrix)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<double> doubleMatrix1 = { { 10.5, -0.25 }, { 6.3, 4.47 } };
    LinAlg::Matrix<double> doubleMatrix2 = { { 4, 7 }, { 2, 6 } };
    LinAlg::Matrix<double> tempDoubleMatrix = doubleMatrix1 / doubleMatrix2;
    doubleMatrix1 /= doubleMatrix2;
    EXPECT_TRUE(doubleMatrix1 == tempDoubleMatrix);

    LinAlg::Matrix<int> intMatrix1 = { { 10, 7 }, { -1, 22 }, { 41, 5 } };
    LinAlg::Matrix<int> intMatrix2 = { { 4, 3 }, { 3, 2 } };
    LinAlg::Matrix<int> tempIntMatrix = intMatrix1 / intMatrix2;
    intMatrix1 /= intMatrix2;
    EXPECT_TRUE(intMatrix1 == tempIntMatrix);

    // INVALID MATRIX ARGUMENT SIZE
    LinAlg::Matrix<short> shortMatrix1 = { { 10, -41, 9 }, { 16, 17, 200 } };
    LinAlg::Matrix<short> shortMatrix2 = { { 24, 1 }, { 0, -8 } };
    ASSERT_THROW(shortMatrix1 /= shortMatrix2, std::invalid_argument);

    LinAlg::Matrix<int> intMatrix3 = { { 112 }, { 64 } };
    LinAlg::Matrix<int> intMatrix4 = { { -7, 28 }, { 14, 9 } };
    ASSERT_THROW(intMatrix3 /= intMatrix4, std::invalid_argument);

    // NULL DETERMINANT
    LinAlg::Matrix<long> longMatrix1 = { { 15, 1194, 317 }, { 2381, -42, 1264 }, { 235, 1536, 1025 } };
    LinAlg::Matrix<long> longMatrix2 = { { 15, 17, 19 }, { -1, 0, 1 }, { 26, 28, 30 } };
    ASSERT_THROW(longMatrix1 /= longMatrix2, std::runtime_error);
}

TEST(LinearAlgebraTest, MethodPow)
{
    // RAISING MATRIX TO ZERO POWER
    LinAlg::Matrix<double> doubleMatrix = { { 1.42, -32.8, 0.9 }, { 10.1, 7.05, 6.4 }, { 1.5, 5.832, -0.63 } };
    LinAlg::Matrix<double> tempDoubleMatrix = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
    doubleMatrix.pow(0);
    EXPECT_TRUE(doubleMatrix == tempDoubleMatrix);

    // RAISING MATRIX TO POSITIVE POWER
    LinAlg::Matrix<short> shortMatrix = { { 10, -2, 3 }, { 0, 27, 4 }, { 9, 16, -5  } };
    LinAlg::Matrix<short> tempShortMatrix = { { 127, -26, 7 }, { 36, 793, 88 }, { 45, 334, 116 } };
    shortMatrix.pow(2);
    EXPECT_TRUE(shortMatrix == tempShortMatrix);

    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    LinAlg::Matrix<int> tempIntMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    intMatrix.pow(1);
    EXPECT_TRUE(intMatrix == tempIntMatrix);

    // RAISING MATRIX TO NEGATIVE POWER
    LinAlg::Matrix<long> longMatrix = { { 2, 5, 7 }, { 6, 3, 4 }, { 5, -2, -3  } };
    LinAlg::Matrix<long> tempLongMatrix = { { 4357, -4688, 3896 }, { -166000, 178611, -148436 }, { 117336, -126250, 104921 } };
    longMatrix.pow(-3);
    EXPECT_TRUE(longMatrix == tempLongMatrix);

    // NOT SQUARE MATRIX
    LinAlg::Matrix<float> floatMatrix = { { 0.52, 8.5, 11.03 }, { -4.2, 15.47, 13.189 } };
    ASSERT_THROW(floatMatrix.pow(2), std::invalid_argument);
}

TEST(LinearAlgebraTest, OperatorEquality)
{
    // SELF EQUALITY TEST
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2, 3 }, { 4, 5, 6 } };
    EXPECT_TRUE(intMatrix1 == intMatrix1);

    // INEQUALITY OF COLS TEST
    LinAlg::Matrix<int> intMatrix2 = { { 7, 8 }, { 9, 0 } };
    EXPECT_FALSE(intMatrix1 == intMatrix2);

    // INEQUALITY OF ROWS TEST
    LinAlg::Matrix<int> intMatrix3 = { { 10, 14 }, { -12, 50 }, { 273, -45 } };
    EXPECT_FALSE(intMatrix2 == intMatrix3);

    // INEQUALITY OF MATRICES TEST
    LinAlg::Matrix<double> doubleMatrix1 = { { 1.5, -4.2 }, { -5.33, 0 }, { 8.05, 14.37 } };
    LinAlg::Matrix<double> doubleMatrix2 = { { 1.5, -4.2 }, { -5.33, 13.64 }, { 12.23, 14.37 } };
    EXPECT_FALSE(doubleMatrix1 == doubleMatrix2);

    LinAlg::Matrix<double> doubleMatrix3 = { { 0.5142353, 12.11 }, { -4.15, 33.70005302436 } };
    LinAlg::Matrix<double> doubleMatrix4 = { { 0.5142353, 12.11 }, { -4.15, 33.70005302435 } };
    EXPECT_FALSE(doubleMatrix3 == doubleMatrix4);

    // EQUALITY OF MATRICES TEST
    LinAlg::Matrix<short> shortMatrix1 = { { 31, 28, -4 }, { 15, 81, 77 } };
    LinAlg::Matrix<short> shortMatrix2 = { { 31, 28, -4 }, { 15, 81, 77 } };
    EXPECT_TRUE(shortMatrix1 == shortMatrix2);

    LinAlg::Matrix<float> floatMatrix1 = { { 100.235, -24.1521 }, { 0.207, 5.5 } };
    LinAlg::Matrix<float> floatMatrix2 = { { 100.235, -24.1521 }, { 0.207, 5.5 } };
    EXPECT_TRUE(floatMatrix1 == floatMatrix2);

    LinAlg::Matrix<double> doubleMatrix5 = { { 17.12491, -6.33 }, { 0, 42.100053712 }, { 5.311, 4114.375 } };
    LinAlg::Matrix<double> doubleMatrix6 = { { 17.12491, -6.33 }, { 0, 42.100053712 }, { 5.311, 4114.375 } };
    EXPECT_TRUE(doubleMatrix5 == doubleMatrix6);
}

TEST(LinearAlgebraTest, OperatorMultiplicationValueLHS)
{
    // NEGATIVE NUMBER TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
    int intValue = -4;
    intMatrix = intValue * intMatrix;
    EXPECT_EQ(intMatrix.at(2, 1), -40);
    EXPECT_EQ(intMatrix.at(0, 3), -16);
    EXPECT_EQ(intMatrix.at(3, 2), -60);

    // POSITIVE NUMBER TEST
    LinAlg::Matrix<double> doubleMatrix = { { 0.42, 32.1}, { 44.112, 4.0 }, { 34.52, 1.245 } };
    LinAlg::Matrix<double> resultMatrix;
    double doubleValue = 2.0;
    resultMatrix = doubleValue * doubleMatrix;
    EXPECT_DOUBLE_EQ(resultMatrix.at(1, 1), 8.0);
    EXPECT_DOUBLE_EQ(resultMatrix.at(0, 1), 64.2);
    EXPECT_DOUBLE_EQ(resultMatrix.at(2, 0), 69.04);

    // NULL TEST
    LinAlg::Matrix<float> floatMatrix = { { 1.1, 42.0, 4.24 }, { 7.5, 2.275, 1.124 } };
    float floatValue = 0;
    floatMatrix = floatValue * floatMatrix;
    EXPECT_FLOAT_EQ(floatMatrix.at(1, 0), 0);
    EXPECT_FLOAT_EQ(floatMatrix.at(1, 2), 0);
    EXPECT_FLOAT_EQ(floatMatrix.at(0, 0), 0);
}

TEST(LinearAlgebraTest, MethodIsZero)
{
    // MATRIX IS ZERO TEST
    LinAlg::Matrix<double> doubleMatrix(4, 5);
    EXPECT_TRUE(doubleMatrix.is_zero());

    // MATRIX IS NOT ZERO TEST
    LinAlg::Matrix<int> intMatrix = { { 0, 0 }, { 0, 1 } };
    EXPECT_FALSE(intMatrix.is_zero());
}

TEST(LinearAlgebraTest, MethodSwapRow)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 } };
    std::vector<int> rowIntVector0 = intMatrix.get_row(0);
    std::vector<int> rowIntVector1 = intMatrix.get_row(1);
    intMatrix.swap_row(0, 1);
    EXPECT_TRUE(rowIntVector0 == intMatrix.get_row(1) && rowIntVector1 == intMatrix.get_row(0));

    LinAlg::Matrix<double> doubleMatrix = { { -0.52, 13.1 }, { 0, 100.6 }, { 4.125, -6.11 }, { 1.3215, 23.42901 }, { 8.8, -7.05 }, { 17.54, 12.0 } };
    std::vector<double> rowDoubleVector4 = doubleMatrix.get_row(4);
    std::vector<double> rowDoubleVector2 = doubleMatrix.get_row(2);
    doubleMatrix.swap_row(4, 2);
    EXPECT_TRUE(rowDoubleVector4 == doubleMatrix.get_row(2) && rowDoubleVector2 == doubleMatrix.get_row(4));

    // OUT OF RANGE ROW INDEX TEST
    LinAlg::Matrix<short> shortMatrix = { { 9, 52, 0, 17 }, { 1, -28, 9, 10 } };
    ASSERT_THROW(shortMatrix.swap_row(2, 0), std::out_of_range);

    LinAlg::Matrix<float> floatMatrix = { { -1.426 }, { 10.0 }, { 2.181 }, { 5.77 } };
    ASSERT_THROW(floatMatrix.swap_row(1, -1), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodSwapCol)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix = { { 6, 7, 8 }, { 9, 10, 11 } };
    std::vector<int> colIntVector0 = intMatrix.get_col(0);
    std::vector<int> colIntVector2 = intMatrix.get_col(2);
    intMatrix.swap_col(0, 2);
    EXPECT_TRUE(colIntVector0 == intMatrix.get_col(2) && colIntVector2 == intMatrix.get_col(0));

    LinAlg::Matrix<double> doubleMatrix = { { 1.53, 68.4, 8.64, 0.5 }, { 10.0, -1.2, 2.7, 53.8 }, { 8.098, 2.29, 5.94, -3.5 } };
    std::vector<double> colDoubleVector2 = doubleMatrix.get_col(2);
    std::vector<double> colDoubleVector1 = doubleMatrix.get_col(1);
    doubleMatrix.swap_col(2, 1);
    EXPECT_TRUE(colDoubleVector1 == doubleMatrix.get_col(2) && colDoubleVector2 == doubleMatrix.get_col(1));

    // OUT OF RANGE COL INDEX TEST
    LinAlg::Matrix<long> longMatrix = { { 523, 10643, 748, 946 }, { 385, -9581, 73, 99 } };
    ASSERT_THROW(longMatrix.swap_col(-7, 2), std::out_of_range);

    LinAlg::Matrix<float> floatMatrix = { { 1.5, -26.1 }, { 0.01, 9.23 }, { -3.1, 7.94 } };
    ASSERT_THROW(floatMatrix.swap_col(1, 2), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodMultRow)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
    intMatrix.mult_row(1, -7);
    LinAlg::Matrix<int> tempIntMatrix = { { 1, 2, 3, 4 }, { -35, -42, -49, -56 }, { 9, 10, 11, 12 } };
    EXPECT_TRUE(intMatrix == tempIntMatrix);

    LinAlg::Matrix<double> doubleMatrix = { { 1.5, 2.28 }, { -0.7, 10.0 } };
    double doubleValue = 1.5;
    doubleMatrix.mult_row(0, doubleValue);
    LinAlg::Matrix<double> tempDoubleMatrix = { { 2.25, 3.42 }, { -0.7, 10.0 } };
    EXPECT_TRUE(doubleMatrix == tempDoubleMatrix);

    // OUT OF RANGE ROW INDEX TEST
    LinAlg::Matrix<short> shortMatrix = { { 10, 41, 95 }, { 351, 73, 0 } };
    ASSERT_THROW(shortMatrix.mult_row(-1, 2), std::out_of_range);

    LinAlg::Matrix<long> longMatrix = { { 16236, 40235 }, { -984, 3056 } };
    ASSERT_THROW(longMatrix.mult_row(2, 5), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodMultCol)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix = { { 5, -7, 11, 12 }, { 0, 26, -3, -5 } };
    intMatrix.mult_col(2, -10);
    LinAlg::Matrix<int> tempIntMatrix = { { 5, -7, -110, 12 }, { 0, 26, 30, -5 } };
    EXPECT_TRUE(intMatrix == tempIntMatrix);

    LinAlg::Matrix<long long> longlongMatrix = { { 623, 95 }, { 7235, 3424 } };
    long long longlongValue = 158;
    longlongMatrix.mult_col(0, longlongValue);
    LinAlg::Matrix<long long> tempLongLongMatrix = { { 98434, 95 }, { 1143130, 3424 } };
    EXPECT_TRUE(longlongMatrix == tempLongLongMatrix);

    // OUT OF RANGE COL INDEX TEST
    LinAlg::Matrix<short> shortMatrix = { { 10, 41, 95 }, { 351, 73, 0 } };
    ASSERT_THROW(shortMatrix.mult_col(-2, 10), std::out_of_range);

    LinAlg::Matrix<float> floatMatrix = { { 6.24, 24.81 }, { -100.0, 7.88 } };
    ASSERT_THROW(floatMatrix.mult_col(23, 5), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodAddRow)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    intMatrix.add_row(0, 2, 2);
    LinAlg::Matrix<int> tempIntMatrix = { { 15, 18, 21 }, { 4, 5, 6 }, { 7, 8, 9 } };
    EXPECT_TRUE(intMatrix == tempIntMatrix);

    LinAlg::Matrix<double> doubleMatrix = { { -0.325, 3.15 }, { 2.7, -4.9 }, { 0.9, 11.0 }, { 22.6, 50.5 }, { 7.05, -1.53 }, { 6.94, 2.72 } };
    doubleMatrix.add_row(4, 2, -3);
    LinAlg::Matrix<double> tempDoubleMatrix = { { -0.325, 3.15 }, { 2.7, -4.9 }, { 0.9, 11.0 }, { 22.6, 50.5 }, { 4.35, -34.53 }, { 6.94, 2.72 } };
    EXPECT_TRUE(doubleMatrix == tempDoubleMatrix);

    // ROW SELF-ADDITION TEST
    LinAlg::Matrix<short> shortMatrix = { { 11, 64, 27 }, { 23, -5, 75 }, { 62, 0, -8 }, { 94, 22, -46 } };
    shortMatrix.add_row(2, 2, 4);
    LinAlg::Matrix<short> tempShortMatrix = { { 11, 64, 27 }, { 23, -5, 75 }, { 310, 0, -40 }, { 94, 22, -46 } };
    EXPECT_TRUE(shortMatrix == tempShortMatrix);

    // NULL VALUE TEST
    LinAlg::Matrix<long> longMatrix = { { 2, -41, 37 }, { 15, 7, 84 }, { 0, -4, 79 } };
    shortMatrix.add_row(1, 0, 0);
    LinAlg::Matrix<long> tempLongMatrix = { { 2, -41, 37 }, { 15, 7, 84 }, { 0, -4, 79 } };
    EXPECT_TRUE(longMatrix == tempLongMatrix);

    // OUT OF RANGE ROW INDEX TEST
    LinAlg::Matrix<float> floatMatrix = { { 0.53, -1.7 }, { 9.56, 20.0 } };
    ASSERT_THROW(floatMatrix.add_row(1, 2, 2), std::out_of_range);
}

TEST(LinearAlgebraTest, MethodAddCol)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    intMatrix.add_col(0, 2, 3);
    LinAlg::Matrix<int> tempIntMatrix = { { 10, 2, 3 }, { 22, 5, 6 }, { 34, 8, 9 } };
    EXPECT_TRUE(intMatrix == tempIntMatrix);

    LinAlg::Matrix<double> doubleMatrix = { { 1.5, -0.67, 8.45, 3.59 }, { 0.312, 10.0, -7.51, 9.75 } };
    doubleMatrix.add_col(3, 1, -1);
    LinAlg::Matrix<double> tempDoubleMatrix = { { 1.5, -0.67, 8.45, 4.26 }, { 0.312, 10.0, -7.51, -0.25 } };
    EXPECT_TRUE(doubleMatrix == tempDoubleMatrix);

    // COL SELF-ADDITION TEST
    LinAlg::Matrix<short> shortMatrix = { { 0, -7, 95, 26 }, { 97, 65, -1, 8 } };
    shortMatrix.add_col(2, 2, -2);
    LinAlg::Matrix<short> tempShortMatrix = { { 0, -7, -95, 26 }, { 97, 65, 1, 8 } };
    EXPECT_TRUE(shortMatrix == tempShortMatrix);

    // NULL VALUE TEST
    LinAlg::Matrix<long> longMatrix = { { 640, 75, 969 }, { -573, 67, 9236 }, { 856, -79, 10 } };
    shortMatrix.add_col(1, 2, 0);
    LinAlg::Matrix<long> tempLongMatrix = { { 640, 75, 969 }, { -573, 67, 9236 }, { 856, -79, 10 } };
    EXPECT_TRUE(longMatrix == tempLongMatrix);

    // OUT OF RANGE COL INDEX TEST
    LinAlg::Matrix<float> floatMatrix = { { -10.89, 9.67, 5.54 }, { 1.25, 2.9, 8.6 } };
    ASSERT_THROW(floatMatrix.add_col(-1, 2, 9), std::out_of_range);
}

TEST(LinearAlgebraTest, InverseMatrixMethod)
{
    // SOLVING MATRIX EQUATION TEST
    LinAlg::Matrix<double> doubleMatrix1 = { { 3, 1, -1 }, { 2, -2, 0 }, { 1, 2, -1 } };
    LinAlg::Matrix<double> doubleMatrix2 = { { 1, 2, -1 }, { 2, 1, 2 }, { -1, 2, 1 } };
    LinAlg::Matrix<double> doubleResult1 = LinAlg::inverse_matrix_method(doubleMatrix1, doubleMatrix2);
    LinAlg::Matrix<double> checkResult1 = doubleMatrix1 * doubleResult1;
    EXPECT_TRUE(checkResult1 == doubleMatrix2);

    LinAlg::Matrix<float> floatMatrix1 = { { 4, -3, 18 }, { 2, 1, 6 }, { 1, -1, 5 } };
    LinAlg::Matrix<float> floatMatrix2 = { { 45, -28 }, { 19, -6 }, { 12, -8 } };
    LinAlg::Matrix<float> floatResult = LinAlg::inverse_matrix_method(floatMatrix1, floatMatrix2);
    LinAlg::Matrix<float> checkResult2 = floatMatrix1 * floatResult;
    EXPECT_TRUE(checkResult2 == floatMatrix2);

    // SOLVING SYSTEM OF LINEAR EQUATIONS TEST
    LinAlg::Matrix<float> floatMatrix3 = { { 1, 2 }, { 3, -5 }, };
    LinAlg::Matrix<float> floatMatrix4 = { { 4 }, { 1 } };
    LinAlg::Matrix<float> floatResult2 = LinAlg::inverse_matrix_method(floatMatrix3, floatMatrix4);
    LinAlg::Matrix<float> checkResult3 = floatMatrix3 * floatResult2;
    EXPECT_TRUE(checkResult3 == floatMatrix4);

    LinAlg::Matrix<double> doubleMatrix3 = { { 4, -1, 0 }, { 3, 2, 5 }, { 1, -3, 4 } };
    LinAlg::Matrix<double> doubleMatrix4 = { { -6 }, { -14 }, { -19 } };
    LinAlg::Matrix<double> doubleResult2 = LinAlg::inverse_matrix_method(doubleMatrix3, doubleMatrix4);
    LinAlg::Matrix<double> checkResult4 = doubleMatrix3 * doubleResult2;
    EXPECT_TRUE(checkResult4 == doubleMatrix4);

    // INVALID MATRICES SIZE TEST
    LinAlg::Matrix<long> longMatrix1 = { { 19, -5, 315 }, { 0, 634, 87 }, { 80, 14, -54 } };
    LinAlg::Matrix<long> longMatrix2 = { { 97, -64 }, { 11, 532 } };
    ASSERT_THROW(LinAlg::inverse_matrix_method(longMatrix1, longMatrix2), std::invalid_argument);

    // NULL DETERMINANT TEST
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    LinAlg::Matrix<int> intMatrix2 = { { 0 }, { 10 }, { 11 } };
    ASSERT_THROW(LinAlg::inverse_matrix_method(intMatrix1, intMatrix2), std::runtime_error);

    // NOT SQUARE MATRIX TEST
    LinAlg::Matrix<short> shortMatrix1 = { { 1, -4 }, { 10, 2 }, { -16, 5 } };
    LinAlg::Matrix<short> shortMatrix2 = { { 13 }, { 9 }, { 27 } };
    ASSERT_THROW(LinAlg::inverse_matrix_method(shortMatrix1, shortMatrix2), std::invalid_argument);
}

TEST(LinearAlgebraTest, MethodResize)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    intMatrix.resize(5, 5);
    LinAlg::Matrix<int> checkMatrix1 = { { 1, 2, 3, 0, 0 }, { 4, 5, 6, 0, 0 }, { 7, 8, 9, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 } };
    EXPECT_EQ(intMatrix.rows(), 5);
    EXPECT_EQ(intMatrix.cols(), 5);
    EXPECT_EQ(intMatrix.vector_size(), 25);
    EXPECT_TRUE(intMatrix == checkMatrix1);

    LinAlg::Matrix<double> doubleMatrix = { { 0.5, 12.27, 5.3, 2.6 }, { -13.8, 2.4, 6.0, 9.9 } };
    doubleMatrix.resize(2, 3);
    LinAlg::Matrix<double> checkMatrix2 = { { 0.5, 12.27, 5.3 }, { -13.8, 2.4, 6.0 } };
    EXPECT_EQ(doubleMatrix.rows(), 2);
    EXPECT_EQ(doubleMatrix.cols(), 3);
    EXPECT_EQ(doubleMatrix.vector_size(), 6);
    EXPECT_TRUE(doubleMatrix == checkMatrix2);

    LinAlg::Matrix<short> shortMatrix = { { -14, 65, 30, 8, 2 }, { 85, -6, 52, 98, 12 }, { 0, -97, 86, 32, 51 } };
    shortMatrix.resize(2, 4);
    LinAlg::Matrix<short> checkMatrix3 = { { -14, 65, 30, 8 }, { 85, -6, 52, 98 } };
    EXPECT_EQ(shortMatrix.rows(), 2);
    EXPECT_EQ(shortMatrix.cols(), 4);
    EXPECT_EQ(shortMatrix.vector_size(), 8);
    EXPECT_TRUE(shortMatrix == checkMatrix3);

    LinAlg::Matrix<float> floatMatrix1 = { { 0.34, -36.7 }, { 64.3, 0.1 } };
    floatMatrix1.resize(0, 0);
    LinAlg::Matrix<float> checkMatrix4 = LinAlg::Matrix<float>();
    EXPECT_EQ(floatMatrix1.rows(), 0);
    EXPECT_EQ(floatMatrix1.cols(), 0);
    EXPECT_EQ(floatMatrix1.vector_size(), 0);
    EXPECT_TRUE(floatMatrix1 == checkMatrix4);

    // INVALID SIZE TEST
    LinAlg::Matrix<long> longMatrix1 = { { 42, 57 }, { 634, 786 }, { 0, -35 } };
    ASSERT_THROW(longMatrix1.resize(-1, 5), std::invalid_argument);

    LinAlg::Matrix<long> longMatrix2 = { { 2355, 657 }, { 956, 574 } };
    ASSERT_THROW(longMatrix2.resize(2, -4), std::invalid_argument);

    LinAlg::Matrix<long long> longlongMatrix = { { 374, 57 }, { 634, 786 }, { 0, -35 } };
    ASSERT_THROW(longlongMatrix.resize(0, 1), std::invalid_argument);

    LinAlg::Matrix<float> floatMatrix2 = { { 0.53 }, { -35.2 }, { 19.14 } };
    ASSERT_THROW(floatMatrix2.resize(3, 0), std::invalid_argument);
}

TEST(LinearAlgebraTest, MethodJoin)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    LinAlg::Matrix<int> intMatrix2 = { { 10 }, { 11 }, { 12 } };
    intMatrix1.join(intMatrix2);
    LinAlg::Matrix<int> checkMatrix1 = { { 1, 2, 3, 10 }, { 4, 5, 6, 11 }, { 7, 8, 9, 12 } };
    EXPECT_EQ(intMatrix1.rows(), 3);
    EXPECT_EQ(intMatrix1.cols(), 4);
    EXPECT_EQ(intMatrix1.vector_size(), 12);
    EXPECT_TRUE(intMatrix1 == checkMatrix1);

    LinAlg::Matrix<double> doubleMatrix1 = { { 0.42, -13.37, 62.6 }, { 6.35, 1.34, 0.14 }, { 7.458, 10.53, 2.5 }, { 2.26, 65.8, -8.35 } };
    LinAlg::Matrix<double> doubleMatrix2 = { { 0 }, { 6.43 }, { -9.75 }, { 53.2 } };
    doubleMatrix1.join(doubleMatrix2);
    LinAlg::Matrix<double> checkMatrix2 = { { 0.42, -13.37, 62.6, 0 }, { 6.35, 1.34, 0.14, 6.43 }, { 7.458, 10.53, 2.5, -9.75 }, { 2.26, 65.8, -8.35, 53.2 } };
    EXPECT_EQ(doubleMatrix1.rows(), 4);
    EXPECT_EQ(doubleMatrix1.cols(), 4);
    EXPECT_EQ(doubleMatrix1.vector_size(), 16);
    EXPECT_TRUE(doubleMatrix1 == checkMatrix2);

    // INVALID MATRIX SIZE TEST
    LinAlg::Matrix<short> shortMatrix1 = { { 23, 45 }, { -51, 75 }, { 8, 0 } };
    LinAlg::Matrix<short> shortMatrix2 = { { 32 }, { -14 }, { 4 }, { 10 } };
    ASSERT_THROW(shortMatrix1.join(shortMatrix2), std::invalid_argument);
}

TEST(LinearAlgebraTest, MethodSeparate)
{
    // DIFFERENT MATRICES TEST
    LinAlg::Matrix<int> intMatrix1 = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
    LinAlg::Matrix<int> intMatrix2(3, 3);
    LinAlg::Matrix<int> intMatrix3(3, 1);
    intMatrix1.separate(3, intMatrix2, intMatrix3);
    LinAlg::Matrix<int> checkLeftMatrix1 = { { 1, 2, 3 }, { 5, 6, 7 }, { 9, 10, 11 } };
    LinAlg::Matrix<int> checkRightMatrix1 = { { 4 }, { 8 }, { 12 } };
    EXPECT_TRUE(intMatrix2 == checkLeftMatrix1);
    EXPECT_TRUE(intMatrix3 == checkRightMatrix1);

    LinAlg::Matrix<double> doubleMatrix1 = { { 1.44, 2.63, -3.5, 7.1, 3.6 }, { 0.53, 0.85, 5.29, 11.2, -5.15 }, { 5.41, -0.33, 4.2, 10.13, 8.7 }, { -3.2, 0, 9.76, 5.11, 7.05 }, { 1.5, 4.3, 0.417, 9.42, 0.848 } };
    LinAlg::Matrix<double> doubleMatrix2(3, 2, 1);
    LinAlg::Matrix<double> doubleMatrix3 = { { 5.2, 1.16 }, { 2.3, -0.11 } };
    doubleMatrix1.separate(4, doubleMatrix2, doubleMatrix3);
    LinAlg::Matrix<double> checkLeftMatrix2 = { { 1.44, 2.63, -3.5, 7.1 }, { 0.53, 0.85, 5.29, 11.2 }, { 5.41, -0.33, 4.2, 10.13 }, { -3.2, 0, 9.76, 5.11 }, { 1.5, 4.3, 0.417, 9.42 } };
    LinAlg::Matrix<double> checkRightMatrix2 = { { 3.6 }, { -5.15 }, { 8.7 }, { 7.05 }, { 0.848 } };
    EXPECT_TRUE(doubleMatrix2 == checkLeftMatrix2);
    EXPECT_TRUE(doubleMatrix3 == checkRightMatrix2);

    LinAlg::Matrix<short> shortMatrix1 = { { 1, 6, 17, 0 }, { 75, 13, -41, 23 }, { -4, 3, 15, 38 } };
    LinAlg::Matrix<short> shortMatrix2(1, 1);
    LinAlg::Matrix<short> shortMatrix3;
    shortMatrix1.separate(3, shortMatrix2, shortMatrix3);
    LinAlg::Matrix<short> checkLeftMatrix3 = { { 1, 6, 17 }, { 75, 13, -41 }, { -4, 3, 15 } };
    LinAlg::Matrix<short> checkRightMatrix3 = { { 0 }, { 23 }, { 38 } };
    EXPECT_TRUE(shortMatrix2 == checkLeftMatrix3);
    EXPECT_TRUE(shortMatrix3 == checkRightMatrix3);

    // OUT OF RANGE COL INDEX TEST
    LinAlg::Matrix<long> longMatrix1 = { { 23, 61, 54, -3 }, { 52, 1243, 6411, -356 }, { 511, 363, 125, -436 } };
    LinAlg::Matrix<long> longMatrix2(3, 3);
    LinAlg::Matrix<long> longMatrix3(3, 1);
    ASSERT_THROW(longMatrix1.separate(5, longMatrix2, longMatrix3), std::out_of_range);

    LinAlg::Matrix<long long> longlongMatrix1 = { { 12, -81, 45 }, { 811, 37, 34 } };
    LinAlg::Matrix<long long> longlongMatrix2(2, 2);
    LinAlg::Matrix<long long> longlongMatrix3(2, 1);
    ASSERT_THROW(longlongMatrix1.separate(-1, longlongMatrix2, longlongMatrix3), std::out_of_range);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
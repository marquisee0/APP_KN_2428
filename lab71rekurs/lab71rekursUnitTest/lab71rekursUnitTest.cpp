
#include "pch.h"
#include "CppUnitTest.h"
#include "../lab71rekurs/lab71rekurs.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTests
{
    TEST_CLASS(MatrixFunctionTests)
    {
    public:
        TEST_METHOD(TestGenerateMatrix)
        {
            int matrix[ROWS][COLS] = { 0 };
            generateMatrix(matrix);

            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    Assert::IsTrue(matrix[i][j] >= 9 && matrix[i][j] <= 61);
                }
            }
        }

        TEST_METHOD(TestSatisfiesCriterion)
        {
            Assert::IsFalse(satisfiesCriterion(15, 0, 7));  
            Assert::IsTrue(satisfiesCriterion(15, 0, 6));  
            Assert::IsTrue(satisfiesCriterion(16, 0, 7));   
            Assert::IsTrue(satisfiesCriterion(16, 0, 6));   
        }

        TEST_METHOD(TestProcessMatrix)
        {
            int testMatrix[ROWS][COLS] = {
                {10, 15, 20, 25, 30, 35},
                {11, 16, 21, 26, 31, 36},
                {12, 17, 22, 27, 32, 37},
                {13, 18, 23, 28, 33, 38},
                {14, 19, 24, 29, 34, 39},
                {15, 20, 25, 30, 35, 40},
                {16, 21, 26, 31, 36, 41}
            };

            int count = 0;
            int sum = 0;
            processMatrix(testMatrix, count, sum);

            Assert::AreEqual(0, testMatrix[0][6]);  
            Assert::AreEqual(0, testMatrix[6][0]); 

            Assert::AreEqual(37, count);  
            Assert::AreEqual(926, sum);
        }

        TEST_METHOD(TestSortMatrix)
        {
            int testMatrix[ROWS][COLS] = {
                {15, 20, 30, 40, 50, 60},
                {10, 25, 30, 40, 50, 60},
                {10, 20, 35, 40, 50, 60},
                {12, 22, 32, 42, 52, 62},
                {10, 20, 30, 40, 50, 60},
                {11, 21, 31, 41, 51, 61},
                {10, 20, 30, 40, 50, 60}
            };

            sortMatrix(testMatrix);

            Assert::IsTrue(testMatrix[0][0] <= testMatrix[1][0]);
            for (int i = 0; i < ROWS - 1; i++) {
                if (testMatrix[i][0] == testMatrix[i + 1][0]) {
                    Assert::IsTrue(testMatrix[i][1] >= testMatrix[i + 1][1]);
                }
            }
        }
    };
}
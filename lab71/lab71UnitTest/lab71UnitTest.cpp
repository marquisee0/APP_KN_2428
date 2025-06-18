#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <random>
#include "../lab71/lab71.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab71UnitTests
{
    TEST_CLASS(MatrixTests)
    {
    public:
        TEST_METHOD(TestGenerateMatrixSize)
        {
            vector<vector<int>> matrix;
            generateMatrix(matrix, 1, 100);

            Assert::AreEqual(ROWS, (int)matrix.size());
            for (const auto& row : matrix) {
                Assert::AreEqual(COLS, (int)row.size());
            }
        }

        TEST_METHOD(TestGenerateMatrixValuesInRange)
        {
            vector<vector<int>> matrix;
            const int min = 10;
            const int max = 50;
            generateMatrix(matrix, min, max);

            for (const auto& row : matrix) {
                for (int val : row) {
                    Assert::IsTrue(val >= min && val <= max);
                }
            }
        }

        TEST_METHOD(TestProcessMatrixCountAndSum)
        {
            vector<vector<int>> matrix(ROWS, vector<int>(COLS, 0));
            // Initialize with test data that matches ROWS and COLS
            matrix[0] = { 10, 11, 12, 13, 14, 15 };
            matrix[1] = { 20, 21, 22, 23, 24, 25 };
            matrix[2] = { 30, 31, 32, 33, 34, 35 };
            // Initialize remaining rows if needed

            int count, sum;
            processMatrix(matrix, count, sum);

            Assert::AreEqual(41, count);
            Assert::AreEqual(370, sum);
        }

        TEST_METHOD(TestSortMatrixRows)
        {
            vector<vector<int>> matrix = {
                {30, 5, 10},
                {20, 3, 15},
                {20, 4, 12},
                {10, 2, 20}
            };

            sortMatrixRows(matrix);

            // Check sorting order:
            // 1. By first column ascending
            // 2. If equal, by second column descending
            // 3. If equal, by third column descending

            Assert::AreEqual(10, matrix[0][0]);
            Assert::AreEqual(20, matrix[1][0]);
            Assert::AreEqual(4, matrix[1][1]);  // Should come before row with 3
            Assert::AreEqual(20, matrix[2][0]);
            Assert::AreEqual(3, matrix[2][1]);
            Assert::AreEqual(30, matrix[3][0]);
        }

        TEST_METHOD(TestSortMatrixRowsWithEqualFirstColumn)
        {
            vector<vector<int>> matrix = {
                {10, 5, 10},
                {10, 3, 15},
                {10, 5, 12},
                {10, 2, 20}
            };

            sortMatrixRows(matrix);

            // Rows with equal first column should be sorted by:
            // 1. Second column descending
            // 2. Third column descending

            Assert::AreEqual(5, matrix[0][1]);
            Assert::AreEqual(12, matrix[0][2]); 

            Assert::AreEqual(5, matrix[1][1]);
            Assert::AreEqual(10, matrix[1][2]);

            Assert::AreEqual(3, matrix[2][1]);
            Assert::AreEqual(2, matrix[3][1]);
        }
    };
}

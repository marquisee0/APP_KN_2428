#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <algorithm>

using namespace std;

const int ROWS = 7;
const int COLS = 6;
const int MIN_VAL = 9;
const int MAX_VAL = 61;

void generateMatrix(vector<vector<int>>& matrix, int minVal, int maxVal) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(minVal, maxVal);

    matrix.resize(ROWS, vector<int>(COLS));
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            matrix[i][j] = dist(gen);
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            cout << setw(4) << val;
        cout << endl;
    }
}

void processMatrix(vector<vector<int>>& matrix, int& count, int& sum) {
    count = 0;
    sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bool isOdd = matrix[i][j] % 2 != 0;
            bool indexSumDivisibleBy7 = ((i + j) % 7 == 0);

            if (!(isOdd && indexSumDivisibleBy7)) {
                sum += matrix[i][j];
                count++;
                matrix[i][j] = 0;
            }
        }
    }
}

void sortMatrixRows(vector<vector<int>>& matrix) {
    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0];          
        if (a[1] != b[1])
            return a[1] > b[1];          
        return a[2] > b[2];              
        });
}

int main() {
    vector<vector<int>> matrix;

    generateMatrix(matrix, MIN_VAL, MAX_VAL);
    cout << "Original matrix:\n";
    printMatrix(matrix);

    sortMatrixRows(matrix);
    cout << "\nMatrix after sorting rows (↑col1, ↓col2, ↓col3):\n";
    printMatrix(matrix);

    int count, sum;
    processMatrix(matrix, count, sum);

    cout << "\nNumber of replaced elements: " << count << endl;
    cout << "Sum of replaced elements: " << sum << endl;

    cout << "\nMatrix after processing (zeros instead of excluded elements):\n";
    printMatrix(matrix);

    return 0;
}

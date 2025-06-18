#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 7;
const int COLS = 6;

void generateMatrix(int matrix[ROWS][COLS], int row = 0, int col = 0) {
    if (row == ROWS) return;
    matrix[row][col] = rand() % (61 - 9 + 1) + 9;
    if (col == COLS - 1)
        generateMatrix(matrix, row + 1, 0);
    else
        generateMatrix(matrix, row, col + 1);
}

void printMatrix(int matrix[ROWS][COLS], int row = 0, int col = 0) {
    if (row == ROWS) return;
    cout << setw(4) << matrix[row][col];
    if (col == COLS - 1) {
        cout << endl;
        printMatrix(matrix, row + 1, 0);
    }
    else {
        printMatrix(matrix, row, col + 1);
    }
}

bool satisfiesCriterion(int value, int i, int j) {
    return !(value % 2 != 0 && (i + j) % 7 == 0);
}

void processMatrix(int matrix[ROWS][COLS], int& count, int& sum, int row = 0, int col = 0) {
    if (row == ROWS) return;

    if (satisfiesCriterion(matrix[row][col], row, col)) {
        count++;
        sum += matrix[row][col];
        matrix[row][col] = 0;
    }

    if (col == COLS - 1)
        processMatrix(matrix, count, sum, row + 1, 0);
    else
        processMatrix(matrix, count, sum, row, col + 1);
}

bool compareRows(int a[COLS], int b[COLS]) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[1] != b[1]) return a[1] > b[1];
    return a[2] > b[2];
}

void sortMatrix(int matrix[ROWS][COLS], int pass = 0, int i = 0) {
    if (pass == ROWS - 1) return;

    if (i < ROWS - pass - 1) {
        if (!compareRows(matrix[i], matrix[i + 1])) {
            for (int j = 0; j < COLS; j++) {
                swap(matrix[i][j], matrix[i + 1][j]);
            }
        }
        sortMatrix(matrix, pass, i + 1);
    }
    else {
        sortMatrix(matrix, pass + 1, 0);
    }
}


int main() {
    srand((unsigned)time(0));

    int matrix[ROWS][COLS];
    int count = 0, sum = 0;

    cout << "Initial matrix:\n";
    generateMatrix(matrix);
    printMatrix(matrix);

    cout << "\nSorted matrix:\n";
    sortMatrix(matrix);
    printMatrix(matrix);

    processMatrix(matrix, count, sum);
    cout << "\nProcessed matrix (elements replaced with 0 if they satisfy the criterion):\n";
    printMatrix(matrix);

    cout << "\nCount of replaced elements: " << count << endl;
    cout << "Sum of replaced elements: " << sum << endl;

    return 0;
}

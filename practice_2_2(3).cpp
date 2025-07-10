//В заданной прямоугольной матрице найти характеристики столбцов.Характеристикой столбца матрицы назовем
//сумму модулей его элементов.В матрице отсортировать столбцы в зависимости от характеристик.

#include <iostream>
#include <cmath>

using namespace std;

int calculateColumnCharacteristic(int** matrix, int rows, int col) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += abs(matrix[i][col]);
    }
    return sum;
}

void swapColumns(int** matrix, int rows, int col1, int col2) {
    for (int i = 0; i < rows; ++i) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

void sortColumnsByCharacteristic(int** matrix, int rows, int cols) {
    int* characteristics = new int[cols];
    for (int j = 0; j < cols; ++j) {
        characteristics[j] = calculateColumnCharacteristic(matrix, rows, j);
    }

    for (int i = 0; i < cols - 1; ++i) {
        for (int j = 0; j < cols - i - 1; ++j) {
            if (characteristics[j] > characteristics[j + 1]) {
                swap(characteristics[j], characteristics[j + 1]);
                swapColumns(matrix, rows, j, j + 1);
            }
        }
    }

    delete[] characteristics;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal matrix:" << endl;
    printMatrix(matrix, rows, cols);

    cout << "\nColumn characteristics:" << endl;
    for (int j = 0; j < cols; ++j) {
        int characteristic = calculateColumnCharacteristic(matrix, rows, j);
        cout << "Column " << j << ": " << characteristic << endl;
    }

    sortColumnsByCharacteristic(matrix, rows, cols);

    cout << "\nMatrix after sorting columns by characteristics:" << endl;
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
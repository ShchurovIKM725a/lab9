#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int matrix[100][100];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int minVal = matrix[0][0], maxVal = matrix[0][0];
    int minRow = 0, maxRow = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minRow = i;
            }
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
            }
        }
    }

    if (minRow != maxRow) {
        for (int j = 0; j < cols; ++j) {
            int temp = matrix[minRow][j];
            matrix[minRow][j] = matrix[maxRow][j];
            matrix[maxRow][j] = temp;
        }
    }

    int primes[10000];
    int k = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
            if (isPrime(matrix[i][j])) {
                primes[k++] = matrix[i][j];
            }
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < k; ++i) {
        cout << primes[i] << " ";
    }

    cout << endl;
}

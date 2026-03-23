#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    double threshold;
    cin >> threshold;

    int rowsCount = 0;

    for (int i = 0; i < n; ++i) {
        double rowSum = 0;

        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
        }

        if (n != 0 && (rowSum / n) < threshold) {
            rowsCount++;
        }
    }

    cout << rowsCount << endl;
}
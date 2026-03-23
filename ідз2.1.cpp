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

    double sum = 0;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (matrix[i][i] < 0) {
            sum += matrix[i][i];
            count++;
        }
    }

    if (count > 0) {
        cout << sum / count << endl;
    }
    else {
        cout << 0 << endl;
    }
}
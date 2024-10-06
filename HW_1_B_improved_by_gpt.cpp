#include <iostream>
#include <vector>
#include <numeric>
#include <set>
using namespace std;

bool isValidMagicSquare(vector<vector<int>>& matrix, int n) {
    int magicSum = n * (n*n + 1) / 2;
    
    // Check rows and columns
    for (int i = 0; i < n; ++i) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum) return false;
    }
    
    // Check diagonals
    int diagSum1 = 0, diagSum2 = 0;
    for (int i = 0; i < n; ++i) {
        diagSum1 += matrix[i][i];
        diagSum2 += matrix[i][n-i-1];
    }
    if (diagSum1 != magicSum || diagSum2 != magicSum) return false;
    
    return true;
}

bool fillMatrix(vector<vector<int>>& matrix, set<int>& used, int n) {
    vector<int> missingPos;
    // Find positions of the missing values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == -1) {
                missingPos.push_back(i*n + j);
            }
        }
    }
    
    // Try to fill missing values
    for (int a = 1; a <= n*n; ++a) {
        if (used.find(a) == used.end()) { // Not used
            for (int b = 1; b <= n*n; ++b) {
                if (a != b && used.find(b) == used.end()) { // Unique and not used
                    for (int c = 1; c <= n*n; ++c) {
                        if (a != c && b != c && used.find(c) == used.end()) { // Unique and not used
                            // Fill the positions with a, b, c
                            matrix[missingPos[0] / n][missingPos[0] % n] = a;
                            matrix[missingPos[1] / n][missingPos[1] % n] = b;
                            matrix[missingPos[2] / n][missingPos[2] % n] = c;
                            if (isValidMagicSquare(matrix, n)) {
                                return true; // Found a valid filling
                            }
                            // Reset the values for next attempt
                            matrix[missingPos[0] / n][missingPos[0] % n] = -1;
                            matrix[missingPos[1] / n][missingPos[1] % n] = -1;
                            matrix[missingPos[2] / n][missingPos[2] % n] = -1;
                        }
                    }
                }
            }
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    set<int> used; // Track used numbers
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string val;
            cin >> val;
            if (val == "_") {
                matrix[i][j] = -1;
            } else {
                matrix[i][j] = stoi(val);
                used.insert(matrix[i][j]);
            }
        }
    }
    
    if (fillMatrix(matrix, used, n)) {
        for (const auto& row : matrix) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution" << endl;
    }
    
    return 0;
}
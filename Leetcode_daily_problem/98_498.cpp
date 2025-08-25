/**
 * Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int m = matrix.size(), n = matrix[0].size();
        vector<int> result(m * n);
        int row = 0, col = 0;

        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];

            if ((row + col) % 2 == 0) {
                if (col == n - 1) row++;
                else if (row == 0) col++;
                else { row--; col++; }
            } else {
                if (row == m - 1) col++;
                else if (col == 0) row++;
                else { row++; col--; }
            }
        }

        return result;
    }
};
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    vector<int> result = sol.findDiagonalOrder(matrix);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
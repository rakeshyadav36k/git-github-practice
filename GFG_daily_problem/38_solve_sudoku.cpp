/**
 * Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], 
 * the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool valid(vector<vector<int>>& mat, int val, int x, int y) {
        for(int j = 0; j < mat[0].size(); j++) if(mat[x][j] == val) return false;
        for(int i = 0; i < mat.size(); i++) if(mat[i][y] == val) return false;
        
        x = 3*(x/3), y = 3*(y/3);
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(mat[x + i][y + j] == val) return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<int>>& mat, vector<pair<int, int>>& to_fill, int index) {
        if(index >= to_fill.size()) return true;
        
        bool res = false;
        
        for(int i = 1; i <= 9; i++) {
            int x = to_fill[index].first, y = to_fill[index].second;
            
            if(valid(mat, i, x, y)) {
                mat[x][y] = i;
                res |= solve(mat, to_fill, index + 1);
                if(res) return true;
                mat[x][y] = 0;
            }
        }
        
        return res;
    }
  
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        vector<pair<int, int>> to_fill;
        int n = mat.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) to_fill.push_back({i, j});
            }
        }
        
        solve(mat, to_fill, 0);
    }
};


vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}

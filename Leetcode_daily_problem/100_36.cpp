/**
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 */
#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    // Check each row
    for (int i = 0; i < 9; i++) {
        unordered_set<char> seen;
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                if (seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
    }

    // Check each column
    for (int j = 0; j < 9; j++) {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++) {
            if (board[i][j] != '.') {
                if (seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
    }

    // Check each 3x3 sub-box
    for (int boxRow = 0; boxRow < 3; boxRow++) {
        for (int boxCol = 0; boxCol < 3; boxCol++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char curr = board[boxRow * 3 + i][boxCol * 3 + j];
                    if (curr != '.') {
                        if (seen.count(curr)) return false;
                        seen.insert(curr);
                    }
                }
            }
        }
    }

    return true;
}

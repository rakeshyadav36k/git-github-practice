/**
 * Given a square matrix mat[][] of size n x n. 
 * The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 
 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        for(int i = 0; i< n/2; i++){
            for(int j = 0; j < n; j++){
                int temp = mat[i][j];
                mat[i][j] = mat[n-1-i][j];
                mat[n-1-i][j] = temp;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

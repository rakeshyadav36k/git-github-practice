/**
 * You are given a 2D matrix mat[][] of size n×m. 
 * The task is to modify the matrix such that if mat[i][j] is 0, 
 * all the elements in the i-th row and j-th column are set to 0 and do it in constant space complexity.
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
     // TC = O(2*(m*n)) SC = O(m) + (n)

    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> row(m, 0), col(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    row[j] = 1;
                    col[i] = 1;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[j] || col[i]){
                    mat[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

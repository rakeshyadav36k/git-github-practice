/**
 * Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, 
 * the task is to find whether element x is present in the matrix.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        int rs = 0, re = n-1;
        for(int i = 0; i < n; i++){  // iterate on rows
   
            if(x >= mat[i][0] && x <= mat[i][m-1]){
                int cs = 0, ce = m-1;
                while(cs <= ce){   // applying binary search on columns
                    int mid = (cs + ce) / 2;
                    if(x == mat[i][mid]) return true;
                    
                    else if(x > mat[i][mid]) cs = mid + 1;
                    else ce = mid - 1;
                }
            }
        }
        
        return false;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

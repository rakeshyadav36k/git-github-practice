/**
 * Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, 
 * find whether element x is present in the matrix.
 * 
Note: In a row-wise sorted matrix, each row is sorted in itself, 
i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1].
 */


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++)
        {
            int l=0,h=mat[i].size()-1;
            
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                
                if(mat[i][mid]==x) return true;
                else if(mat[i][mid] > x) h=mid-1;
                else
                    l=mid+1;
            }
        }
        
        return false;
    }
};
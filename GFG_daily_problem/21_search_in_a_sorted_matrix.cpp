/**
 * Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. 
 * Find whether the number x is present in the matrix or not.
Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, 
and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.
 */

 bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        int tot = row*col -1;
        int s = 0;
        int e = tot;
        while(s<=e){
            int mid = s+(e-s)/2;
            int rIdx = mid/col;
            int cIdx = mid%col;
            if(mat[rIdx][cIdx] == x) return true;
            else if(mat[rIdx][cIdx] < x) s=mid+1;
            else e=mid-1;
        }
        
        return false;
    }
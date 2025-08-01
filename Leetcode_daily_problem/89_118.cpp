/**
 * Leetcode Daily Problem
 * Problem: 118. Pascal's Triangle      
    * Difficulty: Easy 
    * Link: https://leetcode.com/problems/pascals-triangle/
    *                
 */

 class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows, vector<int>(numRows, 0));
        for(int i = 0; i < numRows; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i < numRows; i++){
            for(int j = 1; j <= i; j++){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }

        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++){
            vector<int> temp;
            for(int j = 0; j <= i; j++){
                temp.push_back(dp[i][j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
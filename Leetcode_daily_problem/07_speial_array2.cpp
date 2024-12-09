/**
 * An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.
 */

// ------------ using prefix sum

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefixSumOfValid(nums.size(), 0);
        int cnt = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]%2 == nums[i-1]%2){
                cnt++;
            }
            prefixSumOfValid[i] = cnt;
        }
        
        vector<bool> ans;
        for(auto &range : queries){
            int l = range[0];
            int r = range[1];
            if(prefixSumOfValid[r] - prefixSumOfValid[l] == 0){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }

        return ans;
    }
};
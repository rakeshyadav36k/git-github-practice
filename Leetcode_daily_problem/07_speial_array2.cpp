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


// --------- using binary search
class Solution {
public:

    bool bSearch(vector<int> &vi, int sp, int ep){
        int l = 0;
        int r = vi.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(vi[mid] < sp){
                l = mid + 1;
            }
            else if(vi[mid] > ep){
                r = mid - 1;
            }

            else    // find the violating index
                return true;
        }

        return false;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> vi; // stroe the violating violating indexes
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] % 2 == nums[i-1] % 2){
                vi.push_back(i);
            }
        }

        vector<bool> result(queries.size(), false);
        for(int i = 0; i < queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];

            bool hasAnyViolationIndex = bSearch(vi, start+1, end); 

            if(hasAnyViolationIndex == false){ // did not find any violating index
                result[i] = true;
            }
        }

        return result;
    }
};
/**
 * You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.
 */

class Solution {
public:

    bool check(int mid, vector<int> &nums, int maxOperations) {
        int n = nums.size(); 
        for (auto &num: nums) {
            maxOperations -= (num + mid - 1) / mid - 1;
        }
        return maxOperations >= 0; 
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size(); 
        int l = 1, r = 1e9; 
        int ans = 1e9; 
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            if (check(mid, nums, maxOperations)) {
                ans = mid; 
                r = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }
        return ans; 
    }
};
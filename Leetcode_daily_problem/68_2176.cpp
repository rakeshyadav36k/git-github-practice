/**
 * Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.
 */
class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n = nums.size();
            int res = 0;  // number of pairs meeting the requirements
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if ((i * j) % k == 0 && nums[i] == nums[j]) {
                        ++res;
                    }
                }
            }
            return res;
        }
    };
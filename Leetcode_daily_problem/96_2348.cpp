/**
 * Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.
 */
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, streak = 0;
        for (int num : nums) {
            if (num == 0) {
                streak++;
                cnt += streak;
            } else {
                streak = 0;
            }
        }
        return cnt;
    }
};
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

// Example usage
#include <iostream>
#include <vector>

int main() {
    Solution sol;
    std::vector<int> nums = {1, 0, 0, 2, 0, 0, 0, 3};
    std::cout << sol.zeroFilledSubarray(nums) << std::endl;  // Output: 10
    return 0;
}

/**
 * Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
 */
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLength = 0;
        int zeroCount = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLength = max(maxLength, right - left);
        }

        return maxLength;
    }
};
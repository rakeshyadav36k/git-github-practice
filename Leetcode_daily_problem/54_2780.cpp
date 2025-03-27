/**
 * An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.
 */

 class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            unordered_map<int, int> firstMap, secondMap;
            int n = nums.size();
    
            // Add all elements of nums to second half
            for (auto& num : nums) {
                secondMap[num]++;
            }
    
            for (int index = 0; index < n; index++) {
                // Create split at current index
                int num = nums[index];
                secondMap[num]--;
                firstMap[num]++;
    
                // Check if valid split
                if (firstMap[num] * 2 > index + 1 &&
                    secondMap[num] * 2 > n - index - 1) {
                    return index;
                }
            }
    
            // No valid split exists
            return -1;
        }
    };
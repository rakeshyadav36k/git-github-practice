/**
 * Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.
 */

 class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int count = 0;
    
            // Traverse the array to check all subarrays of length 3
            for (int i = 1; i < nums.size() - 1; ++i) {
                int first = nums[i - 1];
                int middle = nums[i];
                int third = nums[i + 1];
        
                // Check if the condition is satisfied
                if (first + third == middle / 2.0) {
                    ++count;
                }
            }
        
            return count;
        }
    };
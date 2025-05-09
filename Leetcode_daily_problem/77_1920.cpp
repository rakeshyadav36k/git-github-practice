/**
 * Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

 
 */

 class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans;
            for (int i = 0; i < n; ++i) {
                ans.push_back(nums[nums[i]]);
            }
            return ans;
        }
    };

// Build in place
class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n = nums.size();
            // Build the final value on the first iteration
            for (int i = 0; i < n; ++i) {
                nums[i] += 1000 * (nums[nums[i]] % 1000);
            }
            // Modified to final value on the second iteration
            for (int i = 0; i < n; ++i) {
                nums[i] /= 1000;
            }
            return nums;
        }
    };
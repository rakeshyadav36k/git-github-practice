/**
 * You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:

Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.
 */

 // 1st- simulation
 class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            auto checkUnique = [&](int start) {
                unordered_set<int> seen;
                for (int i = start; i < nums.size(); i++) {
                    if (seen.count(nums[i])) {
                        return false;
                    }
                    seen.emplace(nums[i]);
                }
                return true;
            };
    
            int ans = 0;
            for (int i = 0; i < nums.size(); i += 3, ans++) {
                if (checkUnique(i)) {
                    return ans;
                }
            }
            return ans;
        }
    };

    // 2nd - reverse traversal
    class Solution {
        public:
            int minimumOperations(vector<int>& nums) {
                vector<bool> seen(128);
                for (int i = nums.size() - 1; i >= 0; i--) {
                    if (seen[nums[i]]) {
                        return i / 3 + 1;
                    }
                    seen[nums[i]] = true;
                }
                return 0;
            }
        };
/**
 * 
 * The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
 */

 // 1st - generate all subsets using backtracking
 class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            vector<vector<int>> subsets;
            // Generate all of the subsets
            generateSubsets(nums, 0, {}, subsets);
    
            // Compute the XOR total for each subset and add to the result
            int result = 0;
            for (auto& subset : subsets) {
                int subsetXORTotal = 0;
                for (int num : subset) {
                    subsetXORTotal ^= num;
                }
                result += subsetXORTotal;
            }
            return result;
        }
    
    private:
        void generateSubsets(const vector<int>& nums, int index, vector<int> subset,
                             vector<vector<int>>& subsets) {
            // Base case: index reached end of nums
            // Add the current subset to subsets
            if (index == nums.size()) {
                subsets.push_back(subset);
                return;
            }
    
            // Generate subsets with nums[i]
            subset.push_back(nums[index]);
            generateSubsets(nums, index + 1, subset, subsets);
            subset.pop_back();
    
            // Generate subsets without nums[i]
            generateSubsets(nums, index + 1, subset, subsets);
        }
    };

    // 2nd - Optimized Backtracking
    class Solution {
        public:
            int subsetXORSum(vector<int>& nums) {
                return XORSum(nums, 0, 0); 
            }
        
        private:
            int XORSum(vector<int>& nums, int index, int currentXOR) {
                // Return currentXOR when all elements in nums are already considered
                if (index == nums.size()) return currentXOR;
        
                // Calculate sum of subset xor with current element
                int withElement = XORSum(nums, index + 1, currentXOR ^ nums[index]);
        
                // Calculate sum of subset xor without current element
                int withoutElement = XORSum(nums, index + 1, currentXOR);
        
                // Return sum of xor totals
                return withElement + withoutElement;
            }
        };

        // 3rd - bit manupulation
        class Solution {
            public:
                int subsetXORSum(vector<int>& nums) {
                    int result = 0;
                    // Capture each bit that is set in any of the elements
                    for (int num : nums) {
                        result |= num;
                    }
                    // Multiply by the number of subset XOR totals that will have each bit set
                    return result << (nums.size() - 1);
                }
            };
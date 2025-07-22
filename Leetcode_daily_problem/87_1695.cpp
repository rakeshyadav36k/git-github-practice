/**
 * You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
 */

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int maxScore = 0, score = 0;
        unordered_set<int> st;
        while(r < n){
            while(st.find(nums[r]) != st.end()){
                score -= nums[l];
                st.erase(nums[l]);
                l++;
            }
            score += nums[r];
            st.insert(nums[r]);
            maxScore = max(maxScore, score);
            r++;
        }
        return maxScore;
    }
};
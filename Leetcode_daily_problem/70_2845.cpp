/**
 * You are given a 0-indexed integer array nums, an integer modulo, and an integer k.

Your task is to find the count of subarrays that are interesting.

A subarray nums[l..r] is interesting if the following condition holds:

Let cnt be the number of indices i in the range [l, r] such that nums[i] % modulo == k. Then, cnt % modulo == k.
Return an integer denoting the count of interesting subarrays.

Note: A subarray is a contiguous non-empty sequence of elements within an array.
 */

 class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            int n = nums.size();
            unordered_map<int, int> cnt;
            long long res = 0;
            int prefix = 0;
            cnt[0] = 1;
            for(int i = 0; i < n; i++){
                prefix += nums[i] % modulo == k;
                res += cnt[(prefix - k + modulo) % modulo];
                cnt[prefix % modulo]++;
            }
            return res;
        }
    };
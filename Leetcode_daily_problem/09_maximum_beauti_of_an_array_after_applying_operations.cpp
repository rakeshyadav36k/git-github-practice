/**
 * You are given a 0-indexed array nums and a non-negative integer k.

In one operation, you can do the following:

Choose an index i that hasn't been chosen before from the range [0, nums.length - 1].
Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].
The beauty of the array is the length of the longest subsequence consisting of equal elements.

Return the maximum possible beauty of the array nums after applying the operation any number of times.

Note that you can apply the operation to each index only once.

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the order of the remaining elements.
 */

class Solution {
public:
    static int maximumBeauty(vector<int>& nums, int k) {
        int freq[100001]={0};
        int xMax=0, xMin=1e6;
        for(int x: nums){
            freq[x]++;
            xMax=max(x, xMax);
            xMin=min(x, xMin);
        }
        int cnt=0, maxCnt=0;
        for(int l=xMin, r=xMin; r<=xMax; r++){
            cnt+=freq[r];
            while(r-l>2*k){
                cnt-=freq[l];
                l++;
            }
            maxCnt=max(maxCnt, cnt);
        }
        return maxCnt;
    }
};
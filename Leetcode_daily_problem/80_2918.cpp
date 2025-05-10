/**
 * You are given two arrays nums1 and nums2 consisting of positive integers.

You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.

Return the minimum equal sum you can obtain, or -1 if it is impossible.


 */

 class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;
        for (int i : nums1) {
            sum1 += i;
            if (i == 0) {
                sum1++;
                zero1++;
            }
        }
        for (int i : nums2) {
            sum2 += i;
            if (i == 0) {
                sum2++;
                zero2++;
            }
        }
        if (!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2) {
            return -1;
        }
        return max(sum1, sum2);
    }
};
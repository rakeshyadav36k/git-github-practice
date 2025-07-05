/**
 * You are given an array arr[] of integers. 
 * Your task is to find the maximum sum of the smallest and second smallest elements across all subarrays (of size >= 2) of the given array.
 */
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n =arr.size();
              
        int total =0;
        for(int i=0;i<n-1;i++){
            total =max(total , arr[i+1]+arr[i]);
        }
        return total;
    }
};
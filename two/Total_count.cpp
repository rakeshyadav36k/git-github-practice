/*
You are given an array arr[] of positive integers and a threshold value k.
 For each element in the array, divide it into the minimum number of small integers 
 such that each divided integer is less than or equal to k.
 Compute the total number of these integer across all elements of the array.
*/

class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] % k == 0)
                ans += arr[i] / k;
            
            else
                ans += arr[i] / k + 1;
            
        }
        
        return ans;
    }
};
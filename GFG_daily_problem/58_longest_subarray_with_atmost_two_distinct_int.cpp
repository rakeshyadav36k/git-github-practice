/**
 * Given an array arr[] consisting of positive integers, 
 * your task is to find the length of the longest subarray that contains at most two distinct integers.
 */
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int ans = 0;
        int i=0,j=0;
        while(j < n){
            mp[arr[j]]++;
            while(mp.size() > 2){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0)mp.erase(arr[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
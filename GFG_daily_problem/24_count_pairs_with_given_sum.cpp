/**
 * Given an array arr[] and an integer target. 
 * You have to find numbers of pairs in array arr[] which sums up to given target.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(mp[target-arr[i]] > 0){
                if(target - arr[i] == arr[i]) cnt += mp[target-arr[i]]-1;
                else cnt += mp[target-arr[i]];
                mp[arr[i]]--;
            }
        }
        
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

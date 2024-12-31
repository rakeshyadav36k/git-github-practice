/**
 * Given an array arr[] of non-negative integers. 
 * Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, 
 * the consecutive numbers can be in any order.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        sort(begin(arr), end(arr));
        
        int res = 1;
        int cnt = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == arr[i-1] + 1){
                cnt++;
                res = max(res, cnt);
            } 
            else if(arr[i] != arr[i-1]) { // Check for both '!= arr[i-1] + 1' and '!= arr[i-1]'
                cnt = 1; 
            } 
        }
        
        return res;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}


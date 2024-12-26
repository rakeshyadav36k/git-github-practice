/**
 * Given an array arr[] of positive integers and another integer target. 
 * Determine if there exists two distinct indices such that the sum of there elements is equals to target.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // bool twoSum(vector<int>& arr, int target) {
    //     int n=arr.size();
    //     sort(arr.begin(),arr.end());
    //     int left=0;
    //     int right=n-1;
    //     while(left<right){
    //         int sum=arr[left]+arr[right];
    //         if(sum == target){
    //             return true;
    //         }
    //         else if(sum<target){
    //             left++;
    //         }
    //         else{
    //             right--;
    //         }
    //     }
    //     return false;
    // }

    // using map
    bool twoSum(vector<int>& arr, int target) {
        // code here
        
        int n=arr.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            int x=arr[i];
            if(mp.find(target-x)!=mp.end())
            return true;
            
            mp.insert({x,i});
        }
        
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}


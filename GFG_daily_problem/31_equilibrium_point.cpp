/**
 * Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) such that 
the sum of all elements before that index is the same as the sum of elements after it. 
Return -1 if no such point exists. 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        int leftSum = 0;
        for(int i = 0; i < n; i++){
            int rightSum = totalSum - leftSum - arr[i];
            
            if(leftSum == rightSum){
                return i;
            }
            
            leftSum += arr[i];
        }
        return -1;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}

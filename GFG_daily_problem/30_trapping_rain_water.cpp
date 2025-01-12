/**
 * Given an array arr[] with non-negative integers representing the height of blocks. 
 * If the width of each block is 1, 
 * compute how much water can be trapped between the blocks during the rainy season. 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        vector<int>leftToright(n,0);
        vector<int>rightToleft(n,0);
        int max_val=INT_MIN;
        for(int i=0;i<n;i++){
            max_val=max(max_val,arr[i]);
            leftToright[i]=max_val;
        }
        max_val=INT_MIN;
        for(int i=n-1;i>=0;i--){
            max_val=max(max_val,arr[i]);
            rightToleft[i]=max_val;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(leftToright[i],rightToleft[i]))-arr[i];
        }
        return ans;
    }

    /**
     int maxWater(vector<int> &arr) {
        int n=arr.size();
        int left = 0;
        int right = n-1;
        
        int leftMax = 0;
        int rightMax = 0;
        
        long long ans = 0;
        while(left <= right){
            if(leftMax <= rightMax){
                ans += max(0 , leftMax - arr[left]);
                leftMax = max(leftMax , arr[left]);
                left++;
            }
            else{
                ans += max(0 , rightMax - arr[right]);
                rightMax = max(rightMax , arr[right]);
                right--;
            }
        }
        return ans;
    }
     */
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
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}


 
/*
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int prev_start_time = arr[0][0], prev_end_time = arr[0][1];
        
        for(int i = 1; i < arr.size(); i++){
            int curr_start_time = arr[i][0];
            int curr_end_time = arr[i][1];
            if(prev_end_time >= curr_start_time){ // we can merge intervals
                prev_end_time = max(prev_end_time, curr_end_time);
            }
            
            else{// we can't merge
                res.push_back({prev_start_time, prev_end_time});
                prev_start_time = arr[i][0];
                prev_end_time = arr[i][1];
            }
        }
        res.push_back({prev_start_time, prev_end_time});
        
        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

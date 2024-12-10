/**
 * Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. 
 * Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int cmp(vector<int>& p1, vector<int>& p2){
        return p1[1]<p2[1];
    }
  
    int minRemoval(vector<vector<int>> &intervals) {
        int n=intervals.size(), count=0;
        sort(intervals.begin(), intervals.end(), cmp);
        int start=intervals[0][0], end=intervals[0][1];
        for(int i=1; i<n; ++i){
            if(intervals[i][0]<end){
                count++;
            }else{
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        return count;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

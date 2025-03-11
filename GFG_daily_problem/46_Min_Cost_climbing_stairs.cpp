/**
 * Given an array of integers cost[] where cost[i] is the cost of the ith step on a staircase. 
 * Once the cost is paid, you can either climb one or two steps. Return the minimum cost to reach the top of the floor.
Assume 0-based Indexing. You can either start from the step with index 0, or the step with index 1.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dp[100005];
    int solve(int i, vector<int> &cost){
        if(i <= 1) return 0;
        if(dp[i]!= -1) return dp[i];
        return dp[i] = min(cost[i-1]+solve(i-1, cost), cost[i-2]+solve(i-2, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return solve(n, cost);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}

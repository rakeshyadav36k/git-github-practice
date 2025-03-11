/**
 * There are n stairs, a person standing at the bottom wants to reach the top. 
 * The person can climb either 1 stair or 2 stairs at a time.
 *  Your task is to count the number of ways, the person can reach the top (order does matter).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dp[50];
    int solve(int n){
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = solve(n-1) + solve(n-2);
    }
  
    int countWays(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
        
    }
};

int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

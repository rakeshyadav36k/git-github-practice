/*
You are given a 0-indexed string s and a dictionary of words dictionary. 
You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. 
There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(),dictionary.end());
        vector<int> dp(n + 1); // dp[i] stores the minimum extra characters for s[0:i]

        dp[0] = 0; // Base case, no extra characters for an empty string

        for (int i = 1; i <= n; i++){
            dp[i] = dp[i-1] + 1; // as a worst-case scenario
            for (int j = 1; j <= i; ++j) {
                string current = s.substr(i - j , j);
                if (dict.find(current) != dict.end()) {
                    dp[i] = min(dp[i] , dp[i-j]);
                }
            }
        }

        return dp[n];
    }
};

int main(){
    int t;
    cin >> t;
    while(--t){
        string s;
        getline(cin, s);

        int n;
        cin >> n;
        vector<string> dict(n);

        for(int i = 0; i < n; i++){
            cin >> dict[i];
        }

        Solution obj;
        cout << obj.minExtraChar(s, dict);
    }

    return 0;
}
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
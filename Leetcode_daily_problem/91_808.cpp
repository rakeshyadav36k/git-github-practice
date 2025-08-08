/**
 * LeetCode Daily Problem
 * Problem: 808. Soup Servings  
 * Link: https://leetcode.com/problems/soup-servings/
 * 
 * You have two soups, A and B, each starting with n mL. On every turn, one of the following four serving operations is chosen at random, each with probability 0.25 independent of all previous turns:

pour 100 mL from type A and 0 mL from type B
pour 75 mL from type A and 25 mL from type B
pour 50 mL from type A and 50 mL from type B
pour 25 mL from type A and 75 mL from type B
Note:

There is no operation that pours 0 mL from A and 100 mL from B.
The amounts from A and B are poured simultaneously during the turn.
If an operation asks you to pour more than you have left of a soup, pour all that remains of that soup.
The process stops immediately after any turn in which one of the soups is used up.

Return the probability that A is used up before B, plus half the probability that both soups are used up in the same turn. Answers within 10-5 of the actual answer will be accepted.
 */
class Solution {
public:
    double soupServings(int n) {
        int m = ceil(n / 25.0);
        unordered_map<int, unordered_map<int, double>> dp;

        function<double(int, int)> calculateDP = [&](int i, int j) -> double {
            return (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][j - 1] +
                    dp[max(0, i - 2)][max(0, j - 2)] + dp[i - 1][max(0, j - 3)]) /
                   4;
        };

        dp[0][0] = 0.5;
        for (int k = 1; k <= m; k++) {
            dp[0][k] = 1;
            dp[k][0] = 0;
            for (int j = 1; j <= k; j++) {
                dp[j][k] = calculateDP(j, k);
                dp[k][j] = calculateDP(k, j);
            }
            if (dp[k][k] > 1 - 1e-5) {
                return 1;
            }
        }
        return dp[m][m];
    }
};
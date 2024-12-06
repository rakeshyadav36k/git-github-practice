/**
 * You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

The chosen integers have to be in the range [1, n].
Each integer can be chosen at most once.
The chosen integers should not be in the array banned.
The sum of the chosen integers should not exceed maxSum.
Return the maximum number of integers you can choose following the mentioned rules.
 */

// ---------- using set ---------- TC - O(n)  SC - (m)
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());

        int sum = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(st.find(i) == st.end()){
                sum += i;
                if(sum <= maxSum) cnt++;
            }
        }

        return cnt;
    }
};
/**
 * Given a number k and string s of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of s at most k times.
 */
class Solution {
    public:
        string maxNum;
        // function to explore all swap possibilities
        void solve(string &s, int k, int idx) {
            if (k == 0 || idx == s.length()) {
                if (s > maxNum) maxNum = s;
                return;
            }
    
            char maxDigit = s[idx];
            for (int i = idx + 1; i < s.length(); i++) {
                if (s[i] > maxDigit) {
                    maxDigit = s[i];
                }
            }
    
            // If current digit is already max, find next without using a swap
    
    
            if (maxDigit == s[idx]) {
                solve(s, k, idx + 1);
            } else {
                for (int i = s.length() - 1; i > idx; i--) {
                    if (s[i] == maxDigit) {
                        swap(s[i], s[idx]);
                        solve(s, k - 1, idx + 1);
                        swap(s[i], s[idx]); // backtrack
                    }
                }
            }
        }
      
        // Function to find the largest number after k swaps.
        string findMaximumNum(string& s, int k) {
            maxNum = s;
            solve(s, k, 0);
            return maxNum;
        }
    };
/**
 * A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
 */

 class Solution {
    public:
        long long helper(long long base, long long expo, long long mod) {
            long long ans = 1;
            while (expo > 0) {
                if (expo % 2 == 0) {
                    base = (base * base) % mod;
                    expo = expo / 2;
                } else {
                    ans = (ans * base) % mod;
                    expo -= 1;
                }
            }
            return ans;
        }
    
        int countGoodNumbers(long long n) {
            long long even = (n + 1) / 2;
            long long odd = n / 2;
            long long mod = 1e9 + 7;
            return (int)((helper(5, even, mod) * helper(4, odd, mod)) % mod);
        }
    };
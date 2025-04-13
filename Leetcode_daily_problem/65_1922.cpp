/**
 * A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
 */

 class Solution {
    private:
        static constexpr int mod = 1000000007;
    
    public:
        int countGoodNumbers(long long n) {
            // use fast exponentiation to calculate x^y % mod
            auto quickmul = [](int x, long long y) -> int {
                int ret = 1, mul = x;
                while (y > 0) {
                    if (y % 2 == 1) {
                        ret = (long long)ret * mul % mod;
                    }
                    mul = (long long)mul * mul % mod;
                    y /= 2;
                }
                return ret;
            };
    
            return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
        }
    };
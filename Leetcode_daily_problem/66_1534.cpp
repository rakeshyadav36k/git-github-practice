/**
 * Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.
 */

 // 1st - Enumeration
 class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int n = arr.size(), cnt = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        if (abs(arr[i] - arr[j]) <= a &&
                            abs(arr[j] - arr[k]) <= b &&
                            abs(arr[i] - arr[k]) <= c) {
                            ++cnt;
                        }
                    }
                }
            }
            return cnt;
        }
    };


// 2nd - optimized
class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int ans = 0, n = arr.size();
            vector<int> sum(1001, 0);
            for (int j = 0; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (abs(arr[j] - arr[k]) <= b) {
                        int lj = arr[j] - a, rj = arr[j] + a;
                        int lk = arr[k] - c, rk = arr[k] + c;
                        int l = max(0, max(lj, lk)), r = min(1000, min(rj, rk));
                        if (l <= r) {
                            if (l == 0) {
                                ans += sum[r];
                            } else {
                                ans += sum[r] - sum[l - 1];
                            }
                        }
                    }
                }
                for (int k = arr[j]; k <= 1000; ++k) {
                    ++sum[k];
                }
            }
            return ans;
        }
    };
/**
 * You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].

Count the number of pairs of points (A, B), where

A is on the upper left side of B, and
there are no other points in the rectangle (or line) they make (including the border).
Return the count.
 */
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            auto& pointA = points[i];
            for (int j = 0; j < n; j++) {
                vector<int> pointB = points[j];
                if (i == j ||
                    !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])) {
                    continue;
                }
                if (n == 2) {
                    ans++;
                    continue;
                }

                bool illegal = false;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }

                    auto& pointTmp = points[k];
                    bool isXContained =
                        pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                    bool isYContained =
                        pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];
                    if (isXContained && isYContained) {
                        illegal = true;
                        break;
                    }
                }
                if (!illegal) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
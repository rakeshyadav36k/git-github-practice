/**
 * You are given an integer array values where values[i] represents the value of the ith sightseeing spot. 
 * Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.
 */

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int prevMaxSum = values[0] + 0;  // values[i] + i
        int res = 0;
        for(int i = 1; i < n; i++){
            res = max(res, prevMaxSum + values[i] - i);  // prevMaxSum + values[j] - j
            prevMaxSum = max(prevMaxSum, values[i] + i);
        }

        return res;
    }
};
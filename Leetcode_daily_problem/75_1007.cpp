/**
 * In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.
 */

 class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int res = getRotation(tops, bottoms, tops[0]);
            if (tops[0] != bottoms[0]) {
                res = min(res, getRotation(tops, bottoms, bottoms[0]));
            }
            return res == INT_MAX ? -1 : res;
        }
    
    private:
        int getRotation(vector<int>& tops, vector<int>& bottoms, int target) {
            int rotateTop = 0;
            int rotateBottom = 0;
    
            for (int i = 0; i < tops.size(); i++) {
                if (tops[i] != target && bottoms[i] != target) {
                    return INT_MAX;
                }
                if (tops[i] != target) rotateTop++;
                if (bottoms[i] != target) rotateBottom++;
            }
            return min(rotateTop, rotateBottom);
        }
    };
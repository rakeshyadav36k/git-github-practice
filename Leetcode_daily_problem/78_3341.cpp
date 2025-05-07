/**
 * There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.
 */

 class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size(), m = moveTime[0].size();
            vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
            minh.push({0, 0, 0});
            moveTime[0][0] = 0;
    
            vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            while (!minh.empty()) {
                auto current = minh.top();
                minh.pop();
                int currTime = current[0];
                int currRow = current[1];
                int currCol = current[2];
                if (currTime >= dp[currRow][currCol]) continue;
                if (currRow == n - 1 && currCol == m - 1) return currTime;
                dp[currRow][currCol] = currTime;
    
                for (auto& direction : directions) {
                    int nextRow = currRow + direction[0];
                    int nextCol = currCol + direction[1];
                    if (nextRow >= 0 && nextRow < n &&
                        nextCol >= 0 && nextCol < m &&
                        dp[nextRow][nextCol] == INT_MAX) {
                        int nextTime = max(moveTime[nextRow][nextCol], currTime) + 1;
                        minh.push({nextTime, nextRow, nextCol});
                    }
                }
            }
            return -1;
        }
    };
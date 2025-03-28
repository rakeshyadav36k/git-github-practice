/**
 * You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.
 */

 // 1st- Brute force (TLE)
 class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int rowCount = grid.size(), colCount = grid[0].size();
            vector<int> result(queries.size(), 0);
            // Directions for moving in 4 directions (right, down, left, up)
            vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
            // Iterate through each query value
            for (int queryIndex = 0; queryIndex < queries.size(); queryIndex++) {
                int queryValue = queries[queryIndex];
                queue<pair<int, int>> bfsQueue;
                // Start BFS from the top-left corner
                bfsQueue.push({0, 0});
                vector<vector<bool>> visited(rowCount,
                                             vector<bool>(colCount, false));
                // Mark the starting cell as visited
                visited[0][0] = true;
                int points = 0;
    
                // BFS traversal
                while (!bfsQueue.empty()) {
                    int queueSize = bfsQueue.size();
                    while (queueSize--) {
                        auto [currentRow, currentCol] = bfsQueue.front();
                        bfsQueue.pop();
    
                        // If the current cell's value is greater than or equal to
                        // queryValue, stop expanding from here
                        if (grid[currentRow][currentCol] >= queryValue) continue;
    
                        // Count the valid cell
                        points++;
    
                        // Explore all four possible directions
                        for (auto [rowOffset, colOffset] : DIRECTIONS) {
                            int newRow = currentRow + rowOffset,
                                newCol = currentCol + colOffset;
    
                            // Ensure the new position is within bounds and has not
                            // been visited
                            if (newRow >= 0 && newCol >= 0 && newRow < rowCount &&
                                newCol < colCount && !visited[newRow][newCol] &&
                                grid[newRow][newCol] < queryValue) {
                                bfsQueue.push({newRow, newCol});
                                // Mark the new cell as visited
                                visited[newRow][newCol] = true;
                            }
                        }
                    }
                }
                // Store the result for the current query
                result[queryIndex] = points;
            }
            return result;
        }
    };

    // 2nd- sorting queries + min Heap
    class Solution {
        public:
            vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
                int rowCount = grid.size(), colCount = grid[0].size();
                vector<int> result(queries.size(), 0);
                // Directions for movement (right, down, left, up)
                vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
                // Store queries along with their original indices to restore order
                // later
                vector<pair<int, int>> sortedQueries;
                for (int index = 0; index < queries.size(); index++) {
                    sortedQueries.push_back({queries[index], index});
                }
                // Sort queries by value in ascending order
                sort(sortedQueries.begin(), sortedQueries.end());
        
                // Min-heap (priority queue) to process cells in increasing order of
                // value
                priority_queue<pair<int, pair<int, int>>,
                               vector<pair<int, pair<int, int>>>, greater<>>
                    minHeap;
                vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
                // Keeps track of the number of cells processed
                int totalPoints = 0;
                // Start from the top-left cell
                minHeap.push({grid[0][0], {0, 0}});
                visited[0][0] = true;
        
                // Process queries in sorted order
                for (auto [queryValue, queryIndex] : sortedQueries) {
                    // Expand the cells that are smaller than the current query value
                    while (!minHeap.empty() && minHeap.top().first < queryValue) {
                        auto [cellValue, position] = minHeap.top();
                        minHeap.pop();
                        int currentRow = position.first, currentCol = position.second;
                        // Increment count of valid cells
                        totalPoints++;
        
                        // Explore all four possible directions
                        for (auto [rowOffset, colOffset] : DIRECTIONS) {
                            int newRow = currentRow + rowOffset,
                                newCol = currentCol + colOffset;
        
                            // Check if the new cell is within bounds and not visited
                            if (newRow >= 0 && newCol >= 0 && newRow < rowCount &&
                                newCol < colCount && !visited[newRow][newCol]) {
                                minHeap.push({grid[newRow][newCol], {newRow, newCol}});
                                // Mark as visited
                                visited[newRow][newCol] = true;
                            }
                        }
                    }
                    // Store the result for this query
                    result[queryIndex] = totalPoints;
                }
                return result;
            }
        };
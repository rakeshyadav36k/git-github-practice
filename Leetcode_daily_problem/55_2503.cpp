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

// 3rd - priority queue + binary search
class Solution {
    public:
        static constexpr int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int queryCount = queries.size();
            vector<int> result(queryCount);
            int rowCount = grid.size();
            int colCount = grid[0].size();
    
            int totalCells = rowCount * colCount;
            vector<int> thresholdForMaxPoints(totalCells + 1);
    
            vector<vector<int>> minValueToReach(rowCount,
                                                vector<int>(colCount, INT_MAX));
    
            minValueToReach[0][0] = grid[0][0];
    
            // Min-heap for processing cells in increasing order of their maximum
            // encountered value.
            priority_queue<array<int, 3>, vector<array<int, 3>>,
                           greater<array<int, 3>>>
                minHeap;
            minHeap.push({grid[0][0], 0, 0});
            int visitedCells = 0;
    
            // Dijkstra's algorithm to compute minValueToReach for each cell
            while (!minHeap.empty()) {
                array<int, 3> current = minHeap.top();
                minHeap.pop();
    
                // Store the value required to reach `visitedCells` points.
                thresholdForMaxPoints[++visitedCells] = current[0];
    
                // Explore all possible directions.
                for (const auto& direction : DIRECTIONS) {
                    int newRow = current[1] + direction[0];
                    int newCol = current[2] + direction[1];
    
                    // Check if the new position is within bounds and not visited
                    // before.
                    if (newRow >= 0 && newRow < rowCount && newCol >= 0 &&
                        newCol < colCount &&
                        minValueToReach[newRow][newCol] == INT_MAX) {
                        // The max value encountered on the path to this cell.
                        minValueToReach[newRow][newCol] =
                            max(current[0], grid[newRow][newCol]);
    
                        // Add the cell to the heap for further exploration.
                        minHeap.push(
                            {minValueToReach[newRow][newCol], newRow, newCol});
                    }
                }
            }
    
            // Use binary search to determine the maximum number of points that can
            // be collected for each query.
            for (int i = 0; i < queryCount; i++) {
                int threshold = queries[i];
                int left = 0, right = totalCells;
    
                // Find the rightmost number of points we can collect before
                // exceeding the query threshold.
                while (left < right) {
                    int mid = left + (right - left + 1) / 2;
                    if (thresholdForMaxPoints[mid] < threshold) {
                        left = mid;
                    } else {
                        right = mid - 1;
                    }
                }
    
                // Return `left`.
                result[i] = left;
            }
    
            return result;
        }
    };

    // 4th- disjoint set union
    // Represents a cell in the grid with row index, column index, and value
class Cell {
    public:
        int row;
        int col;
        int value;
        Cell(int r, int c, int v) : row(r), col(c), value(v) {}
    };
    
    // Represents a query with its original index and value
    class Query {
    public:
        int index;
        int value;
        Query(int i, int v) : index(i), value(v) {}
    };
    
    bool operator<(const Query& a, const Query& b) { return a.value < b.value; }
    
    bool operator<(const Cell& a, const Cell& b) { return a.value < b.value; }
    
    class UnionFind {
    private:
        vector<int> parent;
        vector<int> size;
    
    public:
        // Initialize all parents to -1 (disjoint sets) and each component starts
        // with size 1
        UnionFind(int n) : parent(vector<int>(n, -1)), size(vector<int>(n, 1)) {}
    
        // Find with path compression
        int find(int node) {
            // If negative, it's the root
            if (parent[node] < 0) {
                return node;
            }
            // Path compression
            return parent[node] = find(parent[node]);
        }
    
        // Union by size (merge smaller tree into larger tree)
        bool union_nodes(int nodeA, int nodeB) {
            int rootA = find(nodeA);
            int rootB = find(nodeB);
            // Already connected
            if (rootA == rootB) {
                return false;
            }
            if (size[rootA] > size[rootB]) {
                parent[rootB] = rootA;
                size[rootA] += size[rootB];
            } else {
                parent[rootA] = rootB;
                size[rootB] += size[rootA];
            }
            return true;
        }
    
        // Get the size of the component containing a given node
        int getSize(int node) { return size[find(node)]; }
    };
    
    // Right, Left, Down, Up
    const vector<int> ROW_DIRECTIONS = {0, 0, 1, -1};
    // Corresponding column moves
    const vector<int> COL_DIRECTIONS = {1, -1, 0, 0};
    
    class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int rowCount = grid.size(), colCount = grid[0].size();
            int totalCells = rowCount * colCount;
    
            // Store queries with their original indices to maintain result order
            vector<Query> sortedQueries;
            for (int i = 0; i < queries.size(); i++) {
                sortedQueries.push_back(Query(i, queries[i]));
            }
            // Sort queries in ascending order
            sort(sortedQueries.begin(), sortedQueries.end());
    
            // Store all grid cells and sort them by value
            vector<Cell> sortedCells;
            for (int row = 0; row < rowCount; row++) {
                for (int col = 0; col < colCount; col++) {
                    sortedCells.push_back(Cell(row, col, grid[row][col]));
                }
            }
            // Sort cells by value
            sort(sortedCells.begin(), sortedCells.end());
    
            // Union-Find to track connected components
            UnionFind uf = UnionFind(totalCells);
            vector<int> result(queries.size());
            int cellIndex = 0;
    
            // Process queries in sorted order
            for (Query query : sortedQueries) {
                // Process cells whose values are smaller than the current query
                // value
                while (cellIndex < totalCells &&
                       sortedCells[cellIndex].value < query.value) {
                    int row = sortedCells[cellIndex].row;
                    int col = sortedCells[cellIndex].col;
                    // Convert 2D position to 1D index
                    int cellId = row * colCount + col;
    
                    // Merge the current cell with its adjacent cells that have
                    // already been processed
                    for (int direction = 0; direction < 4; direction++) {
                        int newRow = row + ROW_DIRECTIONS[direction];
                        int newCol = col + COL_DIRECTIONS[direction];
    
                        // Check if the new cell is within bounds and its value is
                        // smaller than the query value
                        if (newRow >= 0 && newRow < rowCount && newCol >= 0 &&
                            newCol < colCount &&
                            grid[newRow][newCol] < query.value) {
                            uf.union_nodes(cellId, newRow * colCount + newCol);
                        }
                    }
                    cellIndex++;
                }
                // Get the size of the connected component containing the top-left
                // cell (0,0)
                result[query.index] = query.value > grid[0][0] ? uf.getSize(0) : 0;
            }
            return result;
        }
    };
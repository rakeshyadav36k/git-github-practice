/**
 * You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
 */

 // 1st - Dijkstra's Algorithm
 class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            const int MOD = 1e9 + 7;
    
            // Build adjacency list
            vector<vector<pair<int, int>>> graph(n);
            for (auto& road : roads) {
                int startNode = road[0], endNode = road[1], travelTime = road[2];
                graph[startNode].emplace_back(endNode, travelTime);
                graph[endNode].emplace_back(startNode, travelTime);
            }
    
            // Min-Heap (priority queue) for Dijkstra
            priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                           greater<>>
                minHeap;
    
            // Store shortest time to each node
            vector<long long> shortestTime(n, LLONG_MAX);
            // Number of ways to reach each node in shortest time
            vector<int> pathCount(n, 0);
    
            shortestTime[0] = 0;  // Distance to source is 0
            pathCount[0] = 1;     // 1 way to reach node 0
    
            minHeap.emplace(0, 0);  // {time, node}
    
            while (!minHeap.empty()) {
                long long currTime = minHeap.top().first;  // Current shortest time
                int currNode = minHeap.top().second;
                minHeap.pop();
    
                // Skip outdated distances
                if (currTime > shortestTime[currNode]) continue;
    
                for (auto& [neighborNode, roadTime] : graph[currNode]) {
                    // Found a new shortest path → Update shortest time and reset
                    // path count
                    if (currTime + roadTime < shortestTime[neighborNode]) {
                        shortestTime[neighborNode] = currTime + roadTime;
                        pathCount[neighborNode] = pathCount[currNode];
                        minHeap.emplace(shortestTime[neighborNode], neighborNode);
                    }
                    // Found another way with the same shortest time → Add to path
                    // count
                    else if (currTime + roadTime == shortestTime[neighborNode]) {
                        pathCount[neighborNode] =
                            (pathCount[neighborNode] + pathCount[currNode]) % MOD;
                    }
                }
            }
    
            return pathCount[n - 1];
        }
    };

    // 2nd -  Floyd-Warshall algorithm
    #define ll long long int
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ll dp[n][n][2];
        // dp[src][dest][0] stores the minimum time between src and dest
        // dp[src][dest][1] stores the number of ways to reach dest from src
        // with the minimum time

        // Initialize the dp table
        for (ll src = 0; src < n; src++) {
            for (ll dest = 0; dest < n; dest++) {
                if (src != dest) {
                    // Set a large initial time
                    dp[src][dest][0] = 1e12;
                    // No paths yet
                    dp[src][dest][1] = 0;
                } else {
                    // Distance from a node to itself is 0
                    dp[src][dest][0] = 0;
                    // Only one trivial way (staying at the node)
                    dp[src][dest][1] = 1;
                }
            }
        }

        // Initialize direct roads from the input
        for (auto& road : roads) {
            ll startNode = road[0], endNode = road[1], travelTime = road[2];
            dp[startNode][endNode][0] = travelTime;
            dp[endNode][startNode][0] = travelTime;
            // There is one direct path
            dp[startNode][endNode][1] = 1;
            // Since the roads are bidirectional
            dp[endNode][startNode][1] = 1;
        }

        // Apply the Floyd-Warshall algorithm to compute shortest paths
        // Intermediate node
        for (ll mid = 0; mid < n; mid++) {
            // Starting node
            for (ll src = 0; src < n; src++) {
                // Destination node
                for (ll dest = 0; dest < n; dest++) {
                    // Avoid self-loops
                    if (src != mid && dest != mid) {
                        ll newTime = dp[src][mid][0] + dp[mid][dest][0];

                        if (newTime < dp[src][dest][0]) {
                            // Found a shorter path
                            dp[src][dest][0] = newTime;
                            dp[src][dest][1] =
                                (dp[src][mid][1] * dp[mid][dest][1]) % MOD;
                        } else if (newTime == dp[src][dest][0]) {
                            // Another way to achieve the same shortest time
                            dp[src][dest][1] =
                                (dp[src][dest][1] +
                                 dp[src][mid][1] * dp[mid][dest][1]) %
                                MOD;
                        }
                    }
                }
            }
        }

        // Return the number of shortest paths from node (n-1) to node 0
        return dp[n - 1][0][1];
    }
};
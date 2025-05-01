/**
 * You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).

Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.

Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.
 */


 // 1st - Binary Search + Greedy Selection of Workers
 class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                          int strength) {
            int n = tasks.size(), m = workers.size();
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
    
            auto check = [&](int mid) -> bool {
                int p = pills;
                // Ordered set of workers
                multiset<int> ws;
                for (int i = m - mid; i < m; ++i) {
                    ws.insert(workers[i]);
                }
                // Enumerate each task from largest to smallest
                for (int i = mid - 1; i >= 0; --i) {
                    // If the largest element in the ordered set is greater than or
                    // equal to tasks[i]
                    if (auto it = prev(ws.end()); *it >= tasks[i]) {
                        ws.erase(it);
                    } else {
                        if (!p) {
                            return false;
                        }
                        auto rep = ws.lower_bound(tasks[i] - strength);
                        if (rep == ws.end()) {
                            return false;
                        }
                        --p;
                        ws.erase(rep);
                    }
                }
                return true;
            };
    
            int left = 1, right = min(m, n), ans = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (check(mid)) {
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return ans;
        }
    };
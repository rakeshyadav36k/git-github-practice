/**
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.
 */

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        // Map from the node as key to the set of prerequisite nodes.
        unordered_map<int, unordered_set<int>> nodePrerequisites;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adj : adjList[node]) {
                // Add node and prerequisite of node to the prerequisites of adj
                nodePrerequisites[adj].insert(node);
                for (auto prereq : nodePrerequisites[node]) {
                    nodePrerequisites[adj].insert(prereq);
                }

                indegree[adj]--;
                if (!indegree[adj]) {
                    q.push(adj);
                }
            }
        }

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(nodePrerequisites[q[1]].contains(q[0]));
        }

        return answer;
    }
};
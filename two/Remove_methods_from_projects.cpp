/**
 * You are maintaining a project that has n methods numbered from 0 to n - 1.

You are given two integers n and k, and a 2D integer array invocations,
 where invocations[i] = [ai, bi] indicates that method ai invokes method bi.

There is a known bug in method k. Method k, along with any method invoked by it, 
either directly or indirectly, are considered suspicious and we aim to remove them.

A group of methods can only be removed if no method outside the group invokes any methods within it.

Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. 
If it is not possible to remove all the suspicious methods, none should be removed.
 */

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build the adjacency list for the invocation relationships
        vector<vector<int>> adj(n);
        for (const auto& invocation : invocations) {
            adj[invocation[0]].push_back(invocation[1]);
        }

        // Step 2: Perform BFS to find all methods that are suspicious (invoked by or invoking method k)
        unordered_set<int> suspicious = findSuspiciousMethods(n, k, adj);

        // Step 3: Check if any suspicious method is invoked by methods outside the suspicious set
        if (hasExternalInvocation(n, suspicious, adj)) {
            // If there's an external invocation, return all methods
            vector<int> result(n);
            iota(result.begin(), result.end, 0);  // Fills result with 0, 1, 2, ..., n-1
            return result;
        } else {
            // Otherwise, return only non-suspicious methods
            vector<int> result;
            for (int i = 0; i < n; i++) {
                if (suspicious.find(i) == suspicious.end()) {
                    result.push_back(i);
                }
            }
            return result;
        }
    }

private:
    // Helper function to perform BFS and find all suspicious methods
    unordered_set<int> findSuspiciousMethods(int n, int k, const vector<vector<int>>& adj) {
        unordered_set<int> suspicious;
        queue<int> q;
        q.push(k);
        suspicious.insert(k);

        while (!q.empty()) {
            int method = q.front();
            q.pop();

            // Traverse all methods invoked by the current method
            for (int invokedMethod : adj[method]) {
                if (suspicious.find(invokedMethod) == suspicious.end()) {
                    suspicious.insert(invokedMethod);
                    q.push(invokedMethod);
                }
            }
        }
        return suspicious;
    }

    // Helper function to check if there is an external invocation
    bool hasExternalInvocation(int n, const unordered_set<int>& suspicious, const vector<vector<int>>& adj) {
        for (int i = 0; i < n; i++) {
            if (suspicious.find(i) == suspicious.end()) {
                // Check if a non-suspicious method invokes any suspicious method
                for (int invokedMethod : adj[i]) {
                    if (suspicious.find(invokedMethod) != suspicious.end()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/*
class Solution {
public:
    bool hasExternalInvocation(int n, const unordered_set<int>& suspicious, const vector<vector<int>>& adj) {
        for (int i = 0; i < n; i++) {
            if (suspicious.find(i) == suspicious.end()) {
                for (int invokedMethod : adj[i]) {
                    if (suspicious.find(invokedMethod) != suspicious.end()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    
    unordered_set<int> findSuspiciousMethods(int n, int k, const vector<vector<int>>& adj) {
        unordered_set<int> suspicious;
        queue<int> q;
        q.push(k);
        suspicious.insert(k);

        while (!q.empty()) {
            int method = q.front();
            q.pop();

            for (int invokedMethod : adj[method]) {
                if (suspicious.find(invokedMethod) == suspicious.end()) {
                    suspicious.insert(invokedMethod);
                    q.push(invokedMethod);
                }
            }
        }
        return suspicious;
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& invocation : invocations) {
            adj[invocation[0]].push_back(invocation[1]);
        }

        unordered_set<int> suspicious = findSuspiciousMethods(n, k, adj);
        
        if (hasExternalInvocation(n, suspicious, adj)) {
            vector<int> result(n);
            iota(result.begin(), result.end(), 0);  
            return result;
        } else {
            vector<int> result;
            for (int i = 0; i < n; i++) {
                if (suspicious.find(i) == suspicious.end()) {
                    result.push_back(i);
                }
            }
            return result;
        }
    }
};
*/
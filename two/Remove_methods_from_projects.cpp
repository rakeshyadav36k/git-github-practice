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
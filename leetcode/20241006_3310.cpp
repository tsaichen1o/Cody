/**
 * @file 20241006_3310.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 3310. Remove Methods From Project
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n), reverseAdj(n);
        vector<bool> isSuspicious(n, false);
        
        // Build adjacency lists
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
            reverseAdj[inv[1]].push_back(inv[0]);
        }
        
        // Step 1: Mark all methods reachable from k as suspicious using DFS
        stack<int> stack;
        stack.push(k);
        
        while (!stack.empty()) {
            int curr = stack.top();
            stack.pop();
            if (!isSuspicious[curr]) {
                isSuspicious[curr] = true;
                for (int neighbor : adj[curr]) {
                    if (!isSuspicious[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }
        
        // Step 2: Check if any external invocation points to a suspicious method
        for (int method = 0; method < n; ++method) {
            if (isSuspicious[method]) {
                for (int invoker : reverseAdj[method]) {
                    if (!isSuspicious[invoker]) {
                        // External invocation detected, return all methods
                        vector<int> allMethods(n);
                        iota(allMethods.begin(), allMethods.end(), 0);
                        return allMethods;
                    }
                }
            }
        }
        
        // Step 3: Collect non-suspicious methods
        vector<int> remaining;
        for (int i = 0; i < n; ++i) {
            if (!isSuspicious[i]) remaining.push_back(i);
        }
        
        return remaining;
    }
};

//

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Represent invocations in an adjacency list
        vector<vector<int>> adj(n), reverseAdj(n);
        for (auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);         // Normal adjacency for reachability
            reverseAdj[inv[1]].push_back(inv[0]);   // Reverse adjacency to check incoming links
        }
        
        // Step 2: Identify all methods reachable from k (suspicious methods)
        vector<bool> visited(n, false);
        unordered_set<int> suspicious;
        dfs(k, adj, visited, suspicious);
        
        // Step 3: Check if any external methods invoke any suspicious method
        for (int node : suspicious) {
            for (int prev : reverseAdj[node]) {
                if (!suspicious.count(prev)) {
                    // If any external method invokes a suspicious method, return all methods
                    vector<int> allMethods(n);
                    iota(allMethods.begin(), allMethods.end(), 0);
                    return allMethods;
                }
            }
        }
        
        // Step 4: Return remaining methods if all suspicious methods are isolated
        vector<int> remaining;
        for (int i = 0; i < n; ++i) {
            if (!suspicious.count(i)) {
                remaining.push_back(i);
            }
        }
        return remaining;
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, unordered_set<int>& suspicious) {
        if (visited[node]) return;
        visited[node] = true;
        suspicious.insert(node);
        for (int neighbor : adj[node]) {
            dfs(neighbor, adj, visited, suspicious);
        }
    }
};

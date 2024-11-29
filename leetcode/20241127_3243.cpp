/**
 * @file 20241127_3243.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 3243. Shortest Distance After Road Addition Queries I
 * @version 0.1
 * @date 2024-11-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Initial adjacency list for the cities
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
        }
        
        vector<int> shortestDistance;
        
        for (auto& query : queries) {
            int u = query[0], v = query[1];
            adj[u].push_back(v);

            shortestDistance.push_back(bfsShortestPath(adj, n));
        }

        return shortestDistance;
    }

private:
    // Helper function to compute shortest path from 0 to n-1 using BFS
    int bfsShortestPath(vector<vector<int>>& adj, int n) {
        vector<int> distance(n, INT_MAX);
        queue<int> q;
        q.push(0);
        distance[0] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (distance[neighbor] == INT_MAX) {
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return distance[n - 1];
    }
};



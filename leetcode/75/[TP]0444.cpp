/**
 * @file [TP]0444.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 444. Sequence Reconstruction
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& original, vector<vector<int>>& sequences) {
        int n = original.size();
        
        // Create the graph using an unordered_map
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 1; i <= n; ++i) {
            graph[i] = {};
        }

        // Build the graph from sequences
        for (vector<int>& seq : sequences) {
            for (int i = 0; i < seq.size() - 1; ++i) {
                int early_num = seq[i];
                int late_num = seq[i + 1];
                graph[early_num].emplace(late_num);
            }
        }

        // Find indegree for each node
        unordered_map<int, int> indegree = findIndegree(graph);

        // Perform the topological sort to reconstruct the sequence
        return topoSort(graph, original, indegree);
    }

private:
    unordered_map<int, int> findIndegree(unordered_map<int, unordered_set<int>>& graph) {
        unordered_map<int, int> indegree;
        for (auto& [node, neighbors] : graph) {
            indegree[node] = 0;
        }
        for (auto& [node, neighbors] : graph) {
            for (int neighbor : neighbors) {
                indegree[neighbor] += 1;
            }
        }
        return indegree;
    }

    bool topoSort(unordered_map<int, unordered_set<int>>& graph, vector<int>& original, unordered_map<int, int>& indegree) {
        vector<int> reconstructed;
        queue<int> q;

        // Start with nodes that have zero indegree
        for (auto& [node, node_indegree] : indegree) {
            if (node_indegree == 0) {
                q.push(node);
            }
        }

        while (!q.empty()) {
            // If there's more than one node in the queue, reconstruction is not unique
            if (q.size() > 1) return false;

            int node = q.front();
            q.pop();
            reconstructed.emplace_back(node);

            // Process all neighbors and reduce their indegree
            for (int neighbor : graph[node]) {
                indegree[neighbor] -= 1;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check if the reconstructed sequence matches the original
        return original == reconstructed;
    }
};

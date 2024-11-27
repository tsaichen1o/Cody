/**
 * @file 20241126_2914.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2924. Find Champion II
 * @version 0.1
 * @date 2024-11-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int championIdx = -1, championCount = 0;
        vector<int> inDegree(n, 0);

        for (const auto& edge : edges) {
            int v = edge[1];
            inDegree[v]++;
        }

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                championCount++;
                if (championCount > 1) {
                    return -1; // More than one champion candidate found
                }
                championIdx = i;
            }
        }

        return championIdx;
    }
};

/* My */
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int championIdx = -1, championCount = 0;
        vector<int> inDegree(n, 0);
        vector<int> outDegree(n, 0);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Edge from u to v
            outDegree[u]++;
            inDegree[v]++;
        }
        for (int i = 0; i < n; i++) {
            cout << inDegree[i] << ' ' << outDegree[i] <<endl;
            if (inDegree[i] == 0) {
                championCount++;
                championIdx = i;
            }
        }
        if (championCount > 1) championIdx = -1;
        return championIdx;
    }
};
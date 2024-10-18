/**
 * @file 20241018_0973.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 973. K Closest Points to Origin
 * @version 0.1
 * @date 2024-10-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto distance_to_origin = [](const vector<int>& p) {
            return p[0] * p[0] + p[1] * p[1];
        };
        
        auto compare_distance = [&](const vector<int>& p1, const vector<int>& p2) {
            return distance_to_origin(p1) > distance_to_origin(p2);
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare_distance)> heap(compare_distance, move(points));
        vector<vector<int>> res;
        
        for (int i = 0; i < k; i++) {
            res.emplace_back(heap.top());
            heap.pop();
        }
        
        return res;
    }
};

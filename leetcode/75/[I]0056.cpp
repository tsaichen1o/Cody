/**
 * @file [I]0056.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 56. Merge Intervals
 * @version 0.1
 * @date 2024-11-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }

        return res;
    }
};
/**
 * @file 20241012_2406.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2406. Divide Intervals Into Minimum Number of Groups
 * @version 0.1
 * @date 2024-10-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */


/*
 

Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
Example 2:

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.
*/
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        for (const auto& interval : intervals) {
            events.emplace_back(interval[0], 1);  // 开始时间
            events.emplace_back(interval[1] + 1, -1);  // 结束时间
        }
        
        sort(events.begin(), events.end());
        
        int currentOverlap = 0;
        int maxOverlap = 0;
        
        for (const auto& event : events) {
            currentOverlap += event.second;
            maxOverlap = max(maxOverlap, currentOverlap);
        }
        
        return maxOverlap;
    }
};
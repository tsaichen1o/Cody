/**
 * @file 20241002_1331.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1331. Rank Transform of an Array
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> rankMap;
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rankMap.size() + 1;
            }
        }
        for (int& num : arr) {
            num = rankMap[num];
        }
        return arr;
    }
};
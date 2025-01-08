//**
 * @file 20241206_2254.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2554. Maximum Number of Integers to Choose From a Range I
 * @version 0.1
 * @date 2024-12-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        std::unordered_set<int> bannedSet(banned.begin(), banned.end());
        int count = 0;
        int sum = 0;

        for (int i = 1; i <= n; ++i) {
            if (bannedSet.count(i) == 0 && sum + i <= maxSum) {
                sum += i;
                ++count;
            }
        }

        return count;
    }
};

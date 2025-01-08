/**
 * @file [A]0485.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 485. Max Consecutive Ones
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;  // To keep track of the maximum number of consecutive 1s
        int currentCount = 0;  // To keep track of the current streak of 1s

        // Iterate through the array
        for (int num : nums) {
            if (num == 1) {
                // Increment the current count of 1s
                currentCount++;
                // Update the max count if the current count is greater
                maxCount = max(maxCount, currentCount);
            } else {
                // Reset the current count when encountering a 0
                currentCount = 0;
            }
        }

        return maxCount;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// how tol find start and end index of max consecutive ones
// how to find the start and end index of the longest consecutive ones
u=
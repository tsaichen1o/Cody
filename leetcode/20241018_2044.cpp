/**
 * @file 20241018_2044.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2044. Count Number of Maximum Bitwise-OR Subsets
 * @version 0.1
 * @date 2024-10-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    // Helper function for backtracking
    void backtrack(const vector<int>& nums, int index, int currentOr, int maxOr, int& count) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        
        // Include the current number in the subset
        backtrack(nums, index + 1, currentOr | nums[index], maxOr, count);
        
        // Exclude the current number from the subset
        backtrack(nums, index + 1, currentOr, maxOr, count);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0, count = 0;
        
        // Step 1: Calculate the maximum OR value for the entire array
        for (int num : nums) {
            maxOr |= num;
        }
        
        // Step 2: Use backtracking to count the subsets that reach the maximum OR
        backtrack(nums, 0, 0, maxOr, count);
        
        return count;
    }
};

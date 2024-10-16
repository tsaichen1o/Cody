/**
 * @file 20241016_1755.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1755. Closest Subsequence Sum
 * @version 0.1
 * @date 2024-10-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        
        // Split the array into two halves
        vector<int> left(nums.begin(), nums.begin() + n / 2);
        vector<int> right(nums.begin() + n / 2, nums.end());
        
        // Generate all possible sums for each half
        vector<int> leftSums = generateSubsetSums(left);
        vector<int> rightSums = generateSubsetSums(right);
        
        // Sort one of the subset sums lists for binary search
        sort(leftSums.begin(), leftSums.end());
        
        // Initialize the minimum absolute difference
        int minDifference = abs(goal);
        
        // For each sum in rightSums, find the closest sum in leftSums
        for (int sumRight : rightSums) {
            int target = goal - sumRight;
            
            // Use binary search to find the closest sum in leftSums to "target"
            auto lower = lower_bound(leftSums.begin(), leftSums.end(), target);
            
            // Check the closest sums around the lower bound
            if (lower != leftSums.end()) {
                minDifference = min(minDifference, abs(target - *lower));
            }
            if (lower != leftSums.begin()) {
                minDifference = min(minDifference, abs(target - *prev(lower)));
            }
        }
        
        return minDifference;
    }
    
private:
    // Helper function to generate all possible subset sums
    vector<int> generateSubsetSums(const vector<int>& nums) {
        vector<int> subsetSums = {0};
        
        for (int num : nums) {
            int size = subsetSums.size();
            for (int i = 0; i < size; ++i) {
                subsetSums.push_back(subsetSums[i] + num);
            }
        }
        
        return subsetSums;
    }
};

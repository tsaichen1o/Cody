/**
 * @file [PF]0560.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 560. Subarray Sum Equals K
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int targetSum) {
        unordered_map<int, int> prefixSumFrequency;
        prefixSumFrequency[0] = 1; // Base case: a sum of 0 initially.

        int subarrayCount = 0;  // Store the number of subarrays that sum to targetSum.
        int currentSum = 0;     // Store the cumulative sum.

        for (int num : nums) {
            currentSum += num; // Update the cumulative sum.
            
            // If currentSum - targetSum exists, there are subarrays ending here that sum to targetSum.
            subarrayCount += prefixSumFrequency[currentSum - targetSum];
            
            // Increment the frequency of the current cumulative sum.
            prefixSumFrequency[currentSum]++;
        }

        return subarrayCount; // Return the count of subarrays that sum to targetSum.
    }
};

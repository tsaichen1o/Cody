/**
 * @file 20241003_1590.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1590. Make Sum Divisible by P
 * @version 0.1
 * @date 2024-10-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
    long long sum = 0;
    for (int num : nums) {
        sum += num;
    }
    
    int target = sum % p;
    if (target == 0) return 0;
    
    unordered_map<int, int> prefixSum;
    prefixSum[0] = -1;
    int currentSum = 0;
    int minLength = nums.size();
    
    for (int i = 0; i < nums.size(); i++) {
        currentSum = (currentSum + nums[i]) % p;
        int complement = (currentSum - target + p) % p;
        
        if (prefixSum.find(complement) != prefixSum.end()) {
            minLength = min(minLength, i - prefixSum[complement]);
        }
        
        prefixSum[currentSum] = i;
    }
    
    return minLength < nums.size() ? minLength : -1;
    }
};
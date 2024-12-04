/**
 * @file [SW]3350.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 3350. Adjacent Increasing Subarrays Detection II
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
 public:
  // Similar to 3349. Adjacent Increasing Subarrays Detection I
  int maxIncreasingSubarrays(vector<int>& nums) {
    int ans = 0;
    int increasing = 1;
    int prevIncreasing = 0;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        ++increasing;
      } else {
        prevIncreasing = increasing;
        increasing = 1;
      }
      ans = max(ans, increasing / 2);
      ans = max(ans, min(prevIncreasing, increasing));
    }

    return ans;
  }
};
/**
 * @file 20241016_1509.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
 * @version 0.1
 * @date 2024-10-16
 * https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;  // If size is <= 4, all elements can be equalized in 3 moves.
        
        // Sort the array to access smallest and largest elements easily
        sort(nums.begin(), nums.end());
        
        // Calculate the minimum difference across the four scenarios
        return min({
            nums[n-1] - nums[3],   // Remove the smallest 3 elements
            nums[n-2] - nums[2],   // Remove two smallest and one largest
            nums[n-3] - nums[1],   // Remove one smallest and two largest
            nums[n-4] - nums[0]    // Remove the largest 3 elements
        });
    }
};


class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4)
            return 0; // If size is <= 4, we can make all elements equal in 3
                      // moves.

        // Sort the array
        sort(nums.begin(), nums.end());

        // Calculate the minimum difference in the four possible scenarios
        int minDiff = INT_MAX;
        minDiff = min(minDiff,
                      nums[n - 1] - nums[3]); // Replace three smallest elements
        minDiff =
            min(minDiff,
                nums[n - 2] - nums[2]); // Replace two smallest and one largest
        minDiff =
            min(minDiff,
                nums[n - 3] - nums[1]); // Replace one smallest and two largest
        minDiff = min(minDiff,
                      nums[n - 4] - nums[0]); // Replace three largest elements

        return minDiff;
    }
};
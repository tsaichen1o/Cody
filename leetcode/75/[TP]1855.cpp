/**
 * @file [TP]1855.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1855. Maximum Distance Between a Pair of Values
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int maxDist = 0;

        while (i < nums1.size() && j < nums2.size()) {
            // If nums1[i] is smaller or equal to nums2[j], it is a valid pair
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                ++j; // Move `j` to explore further to find a larger distance
            } else {
                ++i; // If not valid, move `i` to a smaller value in `nums1`
            }
        }

        return maxDist;
    }
};

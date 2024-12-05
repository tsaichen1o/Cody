/**
 * @file [TP]0011.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 11. Container With Most Water
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            int current_area =
                std::min(height[left], height[right]) * (right - left);
            max_area = std::max(max_area, current_area);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftPointer = 0;
        int rightPointer = height.size() - 1;
        int maxArea = 0;

        // Iterate until the pointers meet
        while (leftPointer < rightPointer) {
            // Calculate current area
            int minHeight = std::min(height[leftPointer], height[rightPointer]);
            int width = rightPointer - leftPointer;
            int currentArea = minHeight * width;

            // Update maxArea if a larger area is found
            maxArea = std::max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line to find a potentially larger area
            if (height[leftPointer] < height[rightPointer]) {
                leftPointer++;
            } else {
                rightPointer--;
            }
        }

        return maxArea;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
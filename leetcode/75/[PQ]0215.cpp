/**
 * @file [PQ]0215.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 215. Kth Largest Element in an Array
 * @version 0.1
 * @date 2024-11-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <queue>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Use a min-heap of size k
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            // Maintain the heap size to be k
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The top element is the kth largest element
        return minHeap.top();
    }
};

/**
 * @file [PF]0238.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 238. Product of Array Except Self
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> productArray(n, 1);

        // Calculate the product of elements to the left of each element
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            productArray[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // Calculate the product of elements to the right of each element
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            productArray[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return productArray;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
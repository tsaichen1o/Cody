/**
 * @file [TP]0283.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 283. Move Zeroes
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums.at(fast) != 0) {
                int temp = nums.at(slow);
                nums.at(slow) = nums.at(fast);
                nums.at(fast) = temp;
                slow++;
            }
        }
    }
};

// Time Complexity: O(n), where n is the length of the input array.
// Space Complexity: O(1), as it is done in-place.

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
    // copy in-place
    int i = 0;
    for (int n : nums) {
        if (n != 0) {
            nums[i] = n;
            i++;
        }
    }
    // fill rest with zeros
    for (; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
};

// Time Complexity: O(n), where n is the length of the input array.
// Space Complexity: O(1), as it is done in-place.
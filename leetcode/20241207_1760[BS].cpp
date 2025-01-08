/**
 * @file 20241207_1760[BS].cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1760. Minimum Limit of Balls in a Bag
 * @version 0.1
 * @date 2024-12-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Helper function to check if a given penalty is feasible
        auto canDivide = [&](int penalty) {
            int operations = 0;
            for (int balls : nums) {
                if (balls > penalty) {
                    // Calculate the required operations to reduce the size of this bag
                    operations += (balls - 1) / penalty;
                }
                if (operations > maxOperations) {
                    return false; // Exceeded max operations
                }
            }
            return true;
        };
        
        // Binary search for the minimum penalty
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDivide(mid)) {
                result = mid; // Update result and try for a smaller penalty
                right = mid - 1;
            } else {
                left = mid + 1; // Try for a larger penalty
            }
        }
        
        return result;
    }
};

// 2024-12-07
class Solution {
public:
    // Helper function to check if a given penalty is feasible
    bool canDivide(vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > penalty) {
                // Calculate the required operations to reduce the size of this bag
                operations += (balls - 1) / penalty;
            }
            if (operations > maxOperations) {
                return false; // Exceeded max operations
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        // Binary search for the minimum penalty
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, maxOperations, mid)) {
                result = mid; // Update result and try for a smaller penalty
                right = mid - 1;
            } else {
                left = mid + 1; // Try for a larger penalty
            }
        }
        
        return result;
    }
};

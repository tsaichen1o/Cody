/**
 * @file 20241019_1545.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1545. Find Kth Bit in Nth Binary String
 * @version 0.1
 * @date 2024-10-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    char findKthBit(int n, int k) {
        // Helper function to recursively find the k-th bit
        return findBit(n, k);
    }

private:
    char findBit(int n, int k) {
        if (n == 1) return '0'; // Base case, S1 is "0"

        int length = (1 << n) - 1; // Length of Sn is 2^n - 1
        int mid = length / 2 + 1;  // The middle index (1-based)

        if (k == mid) {
            return '1'; // If k is the middle element, return '1'
        } else if (k < mid) {
            return findBit(n - 1, k); // If k is in the first part, recurse on S_{n-1}
        } else {
            // If k is in the second part, find the corresponding bit in S_{n-1}, and invert it
            return invert(findBit(n - 1, length - k + 1));
        }
    }

    // Function to invert a bit ('0' -> '1' and '1' -> '0')
    char invert(char bit) {
        return bit == '0' ? '1' : '0';
    }
};

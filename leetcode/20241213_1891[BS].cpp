/**
 * @file 20241213_1891[BS].cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1891. Cutting Ribbons
 * @version 0.1
 * @date 2024-12-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        // Binary search range
        int left = 1, right = *max_element(ribbons.begin(), ribbons.end());
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canCut(ribbons, k, mid)) {
                result = mid; // Update result if current length is feasible
                left = mid + 1; // Try for a larger length
            } else {
                right = mid - 1; // Try for a smaller length
            }
        }

        return result;
    }

private:
    // Helper function to check if it's possible to cut at least k ribbons of length x
    bool canCut(const vector<int>& ribbons, int k, int x) {
        int count = 0;
        for (int ribbon : ribbons) {
            count += ribbon / x; // Count how many pieces of length x can be cut
            if (count >= k) return true; // Early return if we already have enough
        }
        return count >= k;
    }
};

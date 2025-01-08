/**
 * @file 20241211_2779[SW].cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2779. Maximum Beauty of an Array After Applying Operation
 * @version 0.1
 * @date 2024-12-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& flowers, int k) {
        // Find the range of flower positions
        int minValue = *min_element(flowers.begin(), flowers.end());
        int maxValue = *max_element(flowers.begin(), flowers.end());
        
        // The size of the differential array needs to cover the range of interest
        int rangeSize = maxValue - minValue + k * 2 + 2;
        vector<int> diffArray(rangeSize, 0);

        // Mark the start and end points for each flower range
        for (int flower : flowers) {
            int start = flower - minValue;
            diffArray[start]++;
            diffArray[start + k * 2 + 1]--;
        }

        // Compute the prefix sum to determine maximum beauty
        int currentSum = 0, maxBeauty = 0;
        for (int count : diffArray) {
            currentSum += count;
            maxBeauty = max(maxBeauty, currentSum);
        }

        return maxBeauty;
    }
};

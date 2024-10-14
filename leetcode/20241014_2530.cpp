/**
 * @file 20241014_2530.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2530. Maximal Score After Applying K Operations
 * @version 0.1
 * @date 2024-10-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long maxK = 0;
        priority_queue<long long> heap(nums.begin(), nums.end());
        for (int i = 0; i < k; i++) {
            long long tempMax = heap.top();
            maxK += tempMax;
            cout << tempMax << endl;
            heap.pop();
            // not ceil(tempMax / 3)
            heap.push(ceil(tempMax / 3.0));
        }
        return maxK;
    }
};
/**
 * @file [PF]0303.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 303. Range Sum Query - Immutable
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
using namespace std;

class NumArray {
public:
    // Constructor to initialize the prefix sum array
    NumArray(vector<int>& nums) {
        prefix_sum.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
    }
    
    // Method to get the sum in the given range
    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left];
    }

private:
    vector<int> prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

#include <vector>
using namespace std;

class NumArray {
public:
    // Method to initialize the prefix sum array
    void init(vector<int>& nums) {
        prefix_sum.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
    }
    
    // Method to get the sum in the given range
    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left];
    }

private:
    vector<int> prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj;
 * obj.init(nums);
 * int param_1 = obj.sumRange(left,right);
 */
// Time Complexity: O(n)
// Space Complexity: O(n)
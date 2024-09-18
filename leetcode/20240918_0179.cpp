/**
 * @file 20240918_0719.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 179. Largest Number
 * @version 0.1
 * @date 2024-09-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/*
Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for (int num : nums) {
            snums.push_back(to_string(num));
        }
        
        sort(snums.begin(), snums.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        
        string res;
        for (string& s : snums) {
            res += s;
        }
        
        return res[0] == '0' ? "0" : res;
    }
};

// 3ms
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Custom comparator to sort the numbers in the desired order
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string sa = to_string(a), sb = to_string(b);
            return sa + sb > sb + sa; // Sort based on concatenated result
        });

        // Handle the edge case where the largest number would be "0"
        if (nums[0] == 0) return "0";

        // Efficient concatenation of the sorted numbers
        stringstream res;
        for (int num : nums) {
            res << num;
        }

        return res.str();
    }
};

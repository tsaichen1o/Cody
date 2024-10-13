/**
 * @file 20241013_1679.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1679. Max Number of K-Sum Pairs
 * @version 0.1
 * @date 2024-10-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */




class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        int operations = 0;

        // Count the frequency of each number
        for (int num : nums) {
            frequency[num]++;
        }

        // Iterate through unique elements in the frequency map
        for (const auto& [num, count] : frequency) {
            int complement = k - num;
            // Check if complement exists in the map
            if (frequency.find(complement) != frequency.end()) {
                if (num == complement) {
                    // If the number and complement are the same
                    operations += count / 2;
                } else if (num < complement) {  // To avoid double counting
                    operations += min(count, frequency[complement]);
                }
            }
        }

        return operations;
    }
};


// original solution

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> numMap;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]] = i;
            cout << i << " " << nums[i] << " " << numMap[nums[i]] << endl;
        }

        for (int i = 0; i < nums.size(); i++) {
            int complement = k - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                ans++;
                cout << "Find " << complement << " at " << numMap[complement] << endl;
                nums[numMap[complement]] = -100;
                numMap[nums[i]] = -100;
                nums[i] = -100;
            }
            cout << numMap[nums[i]] << ", " << nums[i] << endl;
        }

        return ans;
    }
};
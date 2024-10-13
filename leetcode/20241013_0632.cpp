/**
 * @file 20241013_0632.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 632. Smallest Range Covering Elements from K Lists
 * @version 0.1
 * @date 2024-10-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */



class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2);
        vector<pair<int, int>> markedGroups;
        int groupCount = nums.size();
        int minRange = INT_MAX;

        // Step 1: Mark each element with its group index and collect all elements
        for (int group = 0; group < groupCount; ++group) {
            for (int num : nums[group]) {
                markedGroups.emplace_back(num, group);
            }
        }

        // Sort all elements by value
        sort(markedGroups.begin(), markedGroups.end());

        // Print sorted pairs (for debugging)
        for (const auto& pair : markedGroups) {
            cout << "[" << pair.first << ", " << pair.second << "] ";
        }
        cout << endl;

        // Step 2: Sliding window with frequency map
        unordered_map<int, int> groupFreq;
        int left = 0, count = 0;

        for (int right = 0; right < markedGroups.size(); ++right) {
            int num = markedGroups[right].first;
            int group = markedGroups[right].second;

            // Add the current group to the frequency map
            if (groupFreq[group] == 0) count++;
            groupFreq[group]++;

            // Shrink the window from the left if all groups are covered
            while (count == groupCount) {
                int minVal = markedGroups[left].first;
                int maxVal = markedGroups[right].first;
                int currentRange = maxVal - minVal;

                if (currentRange < minRange) {
                    minRange = currentRange;
                    ans[0] = minVal;
                    ans[1] = maxVal;
                }

                // Remove the leftmost element from the window
                int leftGroup = markedGroups[left].second;
                groupFreq[leftGroup]--;
                if (groupFreq[leftGroup] == 0) count--;
                left++;
            }
        }

        return ans;
    }
};

// use sliding window

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<pair<int, int>> markedGroups;
        int groupCount = nums.size();
        int minRange = INT_MAX;

        for (int group = 0; group < groupCount; ++group) {
            for (int num : nums[group]) {
                markedGroups.emplace_back(num, group);
            }
        }

        sort(markedGroups.begin(), markedGroups.end());

        for (const auto& pair : markedGroups) {
            cout << "[" << pair.first << ", " << pair.second << "] ";
        }

        int n = markedGroups.size();

        for (int left = 0, right = 0, sum = 0; right < n; ++right) {
            sum +=
                markedGroups[right].second; // Add the current second value to the sum

            // Shrink the window if its size exceeds `targetSize`
            if (right - left + 1 > groupCount) {
                sum -= markedGroups[left]
                           .second; // Remove the leftmost second value from sum
                left++;             // Slide the window to the right
            }

            // Check if the current window is valid and has the target sum
            if (right - left + 1 == groupCount && sum == groupCount) {
                // Find the min and max values of `pairs.first` in the current
                // window
                int minVal = INT_MAX, maxVal = INT_MIN;
                for (int i = left; i <= right; ++i) {
                    minVal = min(minVal, markedGroups[i].first);
                    maxVal = max(maxVal, markedGroups[i].first);
                }

                // Update the minimum range if the current range is smaller
                int currentRange = maxVal - minVal;
                if (currentRange < minRange) {
                    minRange = currentRange;
                    ans.clear();  // Clear any previous result
                    ans.push_back(minVal);  // Push the new minimum value
                    ans.push_back(maxVal); 
                }
            }
        }
        return ans;
    }
};

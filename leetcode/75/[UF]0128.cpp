/**
 * @file [UF]0128.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 128. Longest Consecutive Sequence
 * @version 0.1
 * @date 2024-11-25
 * https://leetcode.com/problems/longest-consecutive-sequence
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create an unordered set to hold unique elements for constant-time lookups.
        unordered_set<int> numbersSet(nums.begin(), nums.end());
        int longestStreak = 0; // Variable to store the length of the longest consecutive sequence found.

        // Iterate over each element in the vector.
        for (int num : nums) {
            // Check if the current number is the beginning of a sequence by looking for num - 1.
            if (!numbersSet.count(num - 1)) {
                // If num is the start of a sequence, look for all consecutive numbers starting with num + 1.
                int currentNum = num + 1;

                // Continue checking for the next consecutive number in the sequence.
                while (numbersSet.count(currentNum)) {
                    currentNum++;
                }

                // Update the longest streak with the length of the current sequence.
                longestStreak = max(longestStreak, currentNum - num);
            }
        }

        // Return the longest length of consecutive sequence found.
        return longestStreak;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> parent;
        unordered_map<int, int> size;

        // Helper function to find the root with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // Union function to merge two sets
        auto unionSets = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        };

        // Initialize Union-Find structure
        for (int num : nums) {
            if (parent.find(num) == parent.end()) {
                parent[num] = num;
                size[num] = 1;
                if (parent.find(num - 1) != parent.end()) {
                    unionSets(num, num - 1);
                }
                if (parent.find(num + 1) != parent.end()) {
                    unionSets(num, num + 1);
                }
            }
        }

        // Find the maximum size among all sets
        int longestStreak = 0;
        for (auto& [key, value] : size) {
            longestStreak = max(longestStreak, value);
        }

        return longestStreak;
    }
};


// 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numCount;
        int consecutiveCount = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            numCount[nums[i]]++;
        }

        // Convert the unordered_map to a vector of pairs
        std::vector<std::pair<int, int>> sortedNumCount(numCount.begin(),
                                                        numCount.end());

        // Sort the vector based on the key
        std::sort(
            sortedNumCount.begin(), sortedNumCount.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.first < b.first;
            });

        // Print the sorted key-value pairs
        for (const auto& num : sortedNumCount) {
            std::cout << num.first << ": " << num.second << std::endl;
        }

        return consecutiveCount;
    }
};
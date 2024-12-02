/**
 * @file [PQ]0347.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 347. Top K Frequent Elements
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// quick select
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Use a priority queue (min-heap) to store top k elements
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        
        for (auto& entry : frequencyMap) {
            minHeap.push(entry);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return result;
    }
};

// bucket sort
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Create a bucket where the index represents the frequency of the elements.
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& entry : frequencyMap) {
            bucket[entry.second].push_back(entry.first);
        }

        // Get the top k frequent elements from the bucket
        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};

// min heap
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Min-heap to store the k most frequent elements
        auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        // Iterate over the frequency map
        for (auto& entry : frequencyMap) {
            minHeap.push(entry);
            if (minHeap.size() > k) {
                minHeap.pop(); // Keep only the top k elements in the heap
            }
        }

        // Prepare the result vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return result;
    }
};
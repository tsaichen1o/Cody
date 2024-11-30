/**
 * @file [PQ]0692.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 692. Top K Frequent Words
 * @version 0.1
 * @date 2024-11-30
 * https://leetcode.com/problems/top-k-frequent-words/
 * @copyright Copyright (c) 2024
 * 
 */

#include <unordered_map>

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<string, int> wordCounts;
        std::vector<string> res;

        // count the frequency of word
        for (const string& word : words)
            wordCounts[word]++;
        for (const auto& wordCount : wordCounts) {
            std::cout << wordCount.first << " " << wordCount.second
                      << std::endl;
        }

        // move elements into a vector of pairs
        std::vector<std::pair<std::string, int>> vec(wordCounts.begin(),
                                                     wordCounts.end());

        // sort vector
        std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            // 1. depends on value first
            if (a.second != b.second) {
                return a.second > b.second;
            }
            // 2. depends on lexicographical order second
            return a.first < b.first;
        });

        for (int i = 0; i < k; i++) {
            res.emplace_back(vec[i].first);
        }

        return res;
    }
};
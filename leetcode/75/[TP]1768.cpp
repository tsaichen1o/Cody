/**
 * @file [TP]1768.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1768. Merge Strings Alternately
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int i = 0, j = 0;
        
        // Iterate through both strings, adding characters alternately
        while (i < word1.size() && j < word2.size()) {
            merged += word1[i++];
            merged += word2[j++];
        }
        
        // Append the remaining characters, if any
        while (i < word1.size()) {
            merged += word1[i++];
        }
        
        while (j < word2.size()) {
            merged += word2[j++];
        }
        
        return merged;
    }
};

// Time Complexity: O(n + m), where n and m are the lengths of word1 and word2, respectively.
// Space Complexity: O(n + m), where n and m are the lengths of word1 and word2, respectively.
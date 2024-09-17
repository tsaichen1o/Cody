/**
 * @file 20240917_0884.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 884. Uncommon Words from Two Sentences
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]
*/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        istringstream iss(s1 + " " + s2);
        string word;
        while (iss >> word) {
            count[word]++;
        }
        
        vector<string> res;
        for (auto& [word, freq] : count) {
            if (freq == 1) {
                res.push_back(word);
            }
        }
        
        return res;
    }
};

// beat 100%
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        string word;
        string s = s1 + " " + s2;
        int n = s.size();

        // Iterate over the combined string s1 + " " + s2 and split manually
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (!word.empty()) {
                    count[word]++;
                    word.clear();
                }
            } else {
                word.push_back(s[i]);
            }
        }

        // Add the last word after the loop (since there might not be a trailing space)
        if (!word.empty()) count[word]++;

        vector<string> res;
        for (const auto& [word, freq] : count) {
            if (freq == 1) res.push_back(word);
        }

        return res;
    }
};

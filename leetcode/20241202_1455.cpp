/**
 * @file 20241202_1455.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
 * @version 0.1
 * @date 2024-12-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss1(sentence);
        vector<string> words1;
        string word;
        int n1 = searchWord.length();
        while (iss1 >> word) words1.push_back(word);
        for (int i = 0; i < words1.size(); i++) {
            // cout << words1[i] << endl;
            int prefixMatch = 0;
            while (prefixMatch < n1 && words1[i][prefixMatch] == searchWord[prefixMatch]) {
                prefixMatch++;
            }
            if (prefixMatch == n1) return i + 1;
        }

        return -1;
    }
};

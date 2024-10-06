/**
 * @file 20241006_1813.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1813. Sentence Similarity III
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.
*/

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
    // 将句子分割成单词
    vector<string> words1, words2;
    istringstream iss1(sentence1), iss2(sentence2);
    string word;
    
    while (iss1 >> word) words1.push_back(word);
    while (iss2 >> word) words2.push_back(word);
    
    // 确保 words1 是较短的句子
    if (words1.size() > words2.size()) swap(words1, words2);
    
    int i = 0, j = 0;
    
    // 检查前缀
    while (i < words1.size() && words1[i] == words2[i]) i++;
    
    // 检查后缀
    while (j < words1.size() - i && 
           words1[words1.size() - 1 - j] == words2[words2.size() - 1 - j]) j++;
    
    // 如果前缀和后缀的总长度等于较短句子的长度，则句子相似
    return i + j == words1.size();
    }
};


// beat 100%
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1, words2;
        istringstream iss1(sentence1), iss2(sentence2);
        string word;
        
        // Split sentences into words
        while (iss1 >> word) words1.push_back(word);
        while (iss2 >> word) words2.push_back(word);

        // Ensure words1 is the shorter sentence
        if (words1.size() > words2.size()) swap(words1, words2);

        int prefixMatch = 0, suffixMatch = 0;
        int n1 = words1.size(), n2 = words2.size();
        
        // Check prefix matches
        while (prefixMatch < n1 && words1[prefixMatch] == words2[prefixMatch]) 
            prefixMatch++;
        
        // Check suffix matches
        while (suffixMatch < n1 - prefixMatch && words1[n1 - 1 - suffixMatch] == words2[n2 - 1 - suffixMatch]) 
            suffixMatch++;
        
        // Return true if total matched length equals shorter sentence
        return prefixMatch + suffixMatch == n1;
    }
};

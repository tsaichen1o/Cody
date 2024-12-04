/**
 * @file [BFS]0127.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 127. Word Ladder
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <unordered_set>
#include <queue>
#include <string>
#include <vector>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not in the wordList, return 0
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        // BFS initialization
        std::queue<std::pair<std::string, int>> bfsQueue;  // Queue stores pair of (word, level)
        bfsQueue.push({beginWord, 1});
        
        while (!bfsQueue.empty()) {
            std::string currentWord = bfsQueue.front().first;
            int level = bfsQueue.front().second;
            bfsQueue.pop();
            
            // Check all possible single-letter transformations
            for (int i = 0; i < currentWord.size(); ++i) {
                char originalChar = currentWord[i];
                
                // Try changing current character to every letter from 'a' to 'z'
                for (char c = 'a'; c <= 'z'; ++c) {
                    currentWord[i] = c;

                    // Skip if it's the same as the original word
                    if (currentWord == bfsQueue.front().first) {
                        continue;
                    }

                    // If the transformed word is the endWord, return the number of transformations
                    if (currentWord == endWord) {
                        return level + 1;
                    }

                    // If the word is in the wordSet, add it to the queue and remove it from the set
                    if (wordSet.find(currentWord) != wordSet.end()) {
                        bfsQueue.push({currentWord, level + 1});
                        wordSet.erase(currentWord);
                    }
                }
                // Restore original character for the next iteration
                currentWord[i] = originalChar;
            }
        }

        // If no valid transformation found, return 0
        return 0;
    }
};

/*
Explanation:
Data Structures:

std::unordered_set<std::string> is used to quickly check if a word exists in the list and to avoid revisiting the same word.
std::queue<std::pair<std::string, int>> is used for BFS to keep track of the current word and its transformation depth (level).
BFS Process:

Start with the beginWord and initialize its level to 1.
For each word, generate all possible words by changing each character from 'a' to 'z'.
If the new word is in wordSet, add it to the queue, increment the level, and remove it from wordSet to mark it as visited.
Continue this process until the endWord is found.
Time Complexity:

The worst-case time complexity is O(M * N), where N is the number of words in the word list, and M is the length of the words. For each word, we can generate up to M * 25 transformations.
Space Complexity:

The space complexity is O(N * M) due to the storage required for the queue and the set.
 */
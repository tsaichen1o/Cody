/**
 * @file [SW]0438.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 438. Find All Anagrams in a String
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> findAnagrams(string text, string pattern) {
        int textLength = text.length();
        int patternLength = pattern.length();

        if (textLength < patternLength) {
            return {}; // Return empty result if the pattern is longer than the
                       // text
        }

        std::vector<int>
            anagramIndices; // Stores the starting indices of all anagrams found

        // Frequency arrays to store character counts
        std::vector<int> patternFrequency(26, 0);
        std::vector<int> currentWindowFrequency(26, 0);

        // Initialize frequency arrays for the pattern and the first window in
        // text
        for (int i = 0; i < patternLength; i++) {
            patternFrequency[pattern[i] - 'a']++;
            currentWindowFrequency[text[i] - 'a']++;
        }

        // Compare the initial window with the pattern frequency
        if (currentWindowFrequency == patternFrequency) {
            anagramIndices.push_back(0);
        }

        // Slide the window over the text
        for (int i = patternLength; i < textLength; i++) {
            // Remove the character going out of the window
            currentWindowFrequency[text[i - patternLength] - 'a']--;
            // Add the character coming into the window
            currentWindowFrequency[text[i] - 'a']++;

            // If the current window matches the pattern frequency, store the
            // starting index
            if (currentWindowFrequency == patternFrequency) {
                anagramIndices.push_back(i - patternLength + 1);
            }
        }

        return anagramIndices;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
/**
 * @file 20240905_2351.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2351. First Letter to Appear Twice
 * @version 0.1
 * @date 2024-09-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    // Function to find the first recurring character in a string
    char repeatedCharacter(string s) {
        // Create an unordered set to store the characters we encounter
        unordered_set<char> seen;

        // Iterate over each character in the string
        for (char c : s) {
            // If the character is already in the set, it's the first recurring
            // character
            if (seen.find(c) != seen.end()) {
                return c; // Return the first recurring character
            }
            // Otherwise, add the character to the set
            seen.insert(c);
        }

        // If no recurring character is found, return null character
        return '\0';
    }
};
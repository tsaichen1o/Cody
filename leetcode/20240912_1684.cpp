/**
 * @file 20240912_1684.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1684. Count the Number of Consistent Strings
 * @version 0.1
 * @date 2024-09-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/*
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
*/
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> charSet(allowed.begin(), allowed.end());
        charSet.erase(' ');
        int count = 0;
        bool tempCount = 0;
        for (const auto word : words) {
            for (const char& c : word) {
                if(charSet.find(c) != charSet.end()) {
                    tempCount = 1;
                } else {
                    tempCount = 0;
                    break;
                }
            }
            cout << tempCount << endl;
            count += tempCount;
        }

        return count;
    }
};


// faster
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a set of allowed characters for fast lookup
        set<char> charSet(allowed.begin(), allowed.end());
        
        int count = 0;  // To count consistent strings
        
        // Iterate through each word in the words vector
        for (const auto& word : words) {
            bool isConsistent = true;  // Assume the word is consistent initially
            
            // Check each character in the word
            for (const char& c : word) {
                // If the character is not in the allowed set, mark the word as inconsistent
                if (charSet.find(c) == charSet.end()) {
                    isConsistent = false;
                    break;
                }
            }
            
            // Increment the count if the word is consistent
            if (isConsistent) {
                count++;
            }
        }
        
        return count;
    }
};

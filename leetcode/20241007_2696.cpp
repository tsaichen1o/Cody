/**
 * @file 20241007_2696.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2696. Minimum String Length After Removing Substrings
 * @version 0.1
 * @date 2024-10-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == 'B' && !st.empty() && st.top() == 'A') {
                st.pop();
            } else if (c == 'D' && !st.empty() && st.top() == 'C') {
                st.pop();
            } else {
                st.push(c);
            }   
        }
        return st.size();
    }
};
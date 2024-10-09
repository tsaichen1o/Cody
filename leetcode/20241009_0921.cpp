/**
 * @file 20241009_0921.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 921. Minimum Add to Make Parentheses Valid
 * @version 0.1
 * @date 2024-10-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftPrnth = 0, rightPrnth = 0;
        for (char& c : s) {
            if (c == '(') {
                leftPrnth++;
            } else if (c == ')' && leftPrnth > 0){
                leftPrnth--;
            } else {
                rightPrnth++;
            }
        }

        return leftPrnth + rightPrnth;
    }
};

// stack
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == ')' && !st.empty() && st.top() == '(') {
                st.pop(); // Found a matching pair, so pop
            } else {
                st.push(c); // Otherwise, push unmatched parentheses
            }
        }
        
        return st.size(); // Stack size is the number of unmatched parentheses
    }
};


The code doesn't need a special check for cases where the string starts with a closing parenthesis ). This is because the logic handles unmatched parentheses by using a stack.
If c is a ) and the stack is empty (meaning there is no ( to balance it), it simply gets pushed onto the stack. This effectively counts as an "unmatched" ) that will require an additional ( later to balance it.

因為最後 ')(' 也是不合理，所以也要當二，就不用考慮開頭是')'的情況了，因為最後一定會有一個'('來配對。
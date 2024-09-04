/**
 * @file 05_DisappearingPairs.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief stack!
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <stack>
using namespace std;

string solution(string &S) {
    stack<char> stk;

    // Iterate over the characters of the string
    for (char ch : S) {
        // Check if the stack is not empty and the current character is the same as the top of the stack
        if (!stk.empty() && ch == stk.top()) {
            // Pop the top of the stack
            stk.pop();
        } else {
            // Push the current character onto the stack
            stk.push(ch);
        }
    }

    // Reconstruct the result string from the stack
    string result;
    while (!stk.empty()) {
        result = stk.top() + result;
        stk.pop();
    }

    return result;
}

// #include <string>
// using namespace std;


// string solution(string &S) {

//     int aaIndex = 0, bbIndex = 0, ccIndex = 0;

//     while (S.find("AA") != string::npos || S.find("BB") != string::npos || S.find("CC") != string::npos) {
//         aaIndex = S.find("AA");
//         S.erase(aaIndex, 2);
//         bbIndex = S.find("BB");
//         S.erase(bbIndex, 2);
//         ccIndex = S.find("CC");
//         S.erase(ccIndex,2);
//     }

//     return S;
// }



#include <string>
using namespace std;

string solution(string &S) {
    // Repeat until none of the substrings "AA", "BB", or "CC" can be found
    while (true) {
        // Find the index of "AA" in the string
        size_t aaIndex = S.find("AA");
        // If "AA" is found, erase it from the string
        if (aaIndex != string::npos) {
            S.erase(aaIndex, 2);
        }
        
        // Find the index of "BB" in the string
        size_t bbIndex = S.find("BB");
        // If "BB" is found, erase it from the string
        if (bbIndex != string::npos) {
            S.erase(bbIndex, 2);
        }

        // Find the index of "CC" in the string
        size_t ccIndex = S.find("CC");
        // If "CC" is found, erase it from the string
        if (ccIndex != string::npos) {
            S.erase(ccIndex, 2);
        }

        // If none of the substrings "AA", "BB", or "CC" can be found, exit the loop
        if (aaIndex == string::npos && bbIndex == string::npos && ccIndex == string::npos) {
            break;
        }
    }

    return S;
}

//
#include <string>
using namespace std;

string solution(string &S) {
    string result = S;

    // Repeat until none of "AA", "BB", or "CC" can be found in the string
    while (result.find("AA") != string::npos || result.find("BB") != string::npos || result.find("CC") != string::npos) {
        // Remove one occurrence of "AA"
        size_t pos = result.find("AA");
        if (pos != string::npos) {
            result.erase(pos, 2);
            continue;
        }

        // Remove one occurrence of "BB"
        pos = result.find("BB");
        if (pos != string::npos) {
            result.erase(pos, 2);
            continue;
        }

        // Remove one occurrence of "CC"
        pos = result.find("CC");
        if (pos != string::npos) {
            result.erase(pos, 2);
            continue;
        }
    }

    return result;
}


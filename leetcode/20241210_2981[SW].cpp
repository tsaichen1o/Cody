/**
 * @file 20241210_2981[SW].cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2981. Find Longest Special Substring That Occurs Thrice I
 * @version 0.1
 * @date 2024-12-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        int result = -1;

        for (int len = 1; len <= n; ++len) {
            unordered_map<string, int> freqMap;
            for (int i = 0; i <= n - len; ++i) {
                string substring = s.substr(i, len);
                if (isSpecial(substring)) {
                    freqMap[substring]++;
                }
            }

            for (const auto& [substring, count] : freqMap) {
                if (count >= 3) {
                    result = max(result, len);
                }
            }
        }

        return result;
    }

private:
    bool isSpecial(const string& str) {
        char ch = str[0];
        for (char c : str) {
            if (c != ch) {
                return false;
            }
        }
        return true;
    }
};

// 
class Solution {
 public:
  int maximumLength(string s) {
    const int n = s.length();
    int ans = -1;
    int runningLen = 0;
    char prevLetter = '@';
    // counts[i][j] := the frequency of ('a' + i) repeating j times
    vector<vector<int>> counts(26, vector<int>(n + 1));

    for (const char c : s)
      if (c == prevLetter) {
        ++counts[c - 'a'][++runningLen];
      } else {
        runningLen = 1;
        ++counts[c - 'a'][runningLen];
        prevLetter = c;
      }

    for (const vector<int>& count : counts)
      ans = max(ans, getMaxFreq(count, n));

    return ans;
  }

 private:
  // Returns the maximum frequency that occurs more than three times.
  int getMaxFreq(const vector<int>& count, int maxFreq) {
    int times = 0;
    for (int freq = maxFreq; freq >= 1; --freq) {
      times += count[freq];
      if (times >= 3)
        return freq;
    }
    return -1;
  }
};
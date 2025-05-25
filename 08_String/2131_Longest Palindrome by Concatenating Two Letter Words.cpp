#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int totalCount = 0;
        unordered_map<string, int> countMap;
        bool hasCenter = false;

        for (const string& word : words) {
            if (word[0] == word[1]) {
                countMap[word]++;
            } else {
                string reversed = string(1, word[1]) + word[0];
                if (countMap[reversed] > 0) {
                    countMap[reversed]--;
                    totalCount += 4;
                } else {
                    countMap[word]++;
                }
            }
        }

        for (const auto& [word, count] : countMap) {
            if (word[0] == word[1]) {
                totalCount += (count / 2) * 4;
                if (count % 2 == 1 && !hasCenter) {
                    totalCount += 2;
                    hasCenter = true;
                }
            }
        }

        return totalCount;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

// ChatGPT solution (wrong)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int res = 0;
        bool hasCenter = false;

        for (const string& word : words) {
            count[word]++;
        }

        for (auto& [word, cnt] : count) {
            string rev = {word[1], word[0]};
            if (word == rev) {
                // 對稱字（如 "gg"）
                res += (cnt / 2) * 4; // 每兩個可放首尾
                if (cnt % 2 == 1) hasCenter = true; // 可留一個做中間
            } else if (word < rev) { // 只算一次，避免重複
                int pairCnt = min(cnt, count[rev]);
                res += pairCnt * 4; // 一對可佔 4 位
            }
        }

        if (hasCenter) res += 2; // 中央還能多放一個

        return res;
    }
};

/*
把每個字串記錄到 unordered_map。

如果是對稱字（如 "gg"）先計數，之後處理能否放在正中央。

若不是對稱字，找反過來的字（如 "ab" 與 "ba"），能配對的就取 min(pair 數量)，雙方各減掉配對數量。

"gg"、"cc" 這種對稱字可以成對放在首尾，剩一個可放正中央

"ab" 配 "ba" 這種互為 swap，配對數 = min(count["ab"], count["ba"])

只對 word < rev 時計算，避免重複配對

每個 word 長度都為 2，所以一對是 4 字元

*/

// Way to reverse a string
// Method 1: using constructor
string reverseString(const string& s) {
    return string(s.rbegin(), s.rend());
}

// Method 2: using reverse function
string reverseString(const string& s) {
    string result = s;
    reverse(result.begin(), result.end());
    return result;
}

// Method 3: manually swap
string reverseString(const string& s) {
    string result = s;
    int left = 0, right = s.length() - 1;
    while (left < right) {
        swap(result[left++], result[right--]);
    }
    return result;
}

// Method 1 is the simplest, but it creates a new string
// Method 2 uses STL algorithm, which is more concise
// Method 3 can reverse in place, which is the most space-efficient
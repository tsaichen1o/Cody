#include <algorithm>

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        int idx = 0;
        std::for_each(words.begin(), words.end(), [&](const string& word) {
            if (word.find(x) != string::npos) {
                result.push_back(idx);
            }
            ++idx;
        });
        return result;
    }
};



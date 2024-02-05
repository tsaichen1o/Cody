/**
 * @file 14_Divisible_Sum_Pairs.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Prepare > Algorithms > Implementation > Divisible Sum Pairs
 * @version 0.1
 * @date 2024-02-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'divisibleSumPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY ar
 */

/*
    使用 O(n) 的解法。
    建立一個計數陣列，用來記錄每個餘數的出現次數。然後，
    對於每一個數字，計算它除以 k 的餘數 r，
    接著檢查計數數組中是否存在 k - r 的餘數，
    如果存在，將相應的計數值加到答案中。
    對於每一個數字，計算它的餘數，
    然後查看 hash table 中是否存在與之相補的餘數，
    如果存在，則將相應的計數值加到答案中，同時更新 hash table。
*/
int divisibleSumPairs(int n, int k, vector<int> ar) {
    unordered_map<int, int> remainderCount;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int remainder = ar[i] % k;
        int complement = (k - remainder) % k;

        count += remainderCount[complement];

        // update remainder count
        remainderCount[remainder]++;
    }

    return count;
    // int length = 0, count = 0;
    // length = ar.size();
    // for (int i = 0; i < length; ++i) {
    //     for (int j = i + 1; j < length; j++) {
    //         if ((ar[i] + ar[j]) % k == 0) {
    //             count++;
    //         }
    //     }
    // }
    
    // return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = divisibleSumPairs(n, k, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

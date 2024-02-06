/**
 * @file 15_Migratory_Birds.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Prepare > Algorithms > Implementation > Migratory Birds
 * @version 0.1
 * @date 2024-02-06
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
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(vector<int> arr) {
    
    unordered_map<int, int> count;
    
    // count every type of birds
    for (int birdType : arr) {
        count[birdType]++;
    }
    
    // find the most frequent
    int maxCount = 0, maxNum = 0;
    for (const auto& pair : count) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxNum = pair.first;
        }
    }
    
    // for (int i = 1; i <= 5; ++i) {
    //     if (arr[i - 1] == i) {
    //         count[i]++;
    //     }  
    // }
    // for (int i = 1; i <= 5; ++i) {
    //     if (count[i] > maxCount) {
    //         maxCount = count[i];
    //         maxNum = i;
    //     }
    // }
    return maxNum;
}

/*
    對於上面的問題，使用 std::map 是一個合適的選擇，因為我們需要計算每種鳥的數量，
    並按照鳥的類型編號進行排序。由於 std::map 會根據鍵的比較函數（默認情況下是 <）對鍵進行排序，
    因此可以保證每種鳥的數量按照鳥的類型編號的順序存儲。這樣在找出最常見的鳥類型時，
    只需要遍歷一次 std::map 即可，而且時間複雜度是 O(n * log n)，其中 n 是鳥的數量。
    另一方面，如果我們不需要按照鳥的類型編號進行排序，只需要計算每種鳥的數量，
    那麼也可以使用 std::unordered_map。std::unordered_map 使用哈希表實現，
    插入、查找和遍歷的時間複雜度均為 O(n)，其中 n 是元素的數量。
    這樣的效率在某些情況下可能會更高，特別是當鳥的類型編號範圍較大時。

*/

int migratoryBirds2(vector<int> arr) {
    // bird type from 1 to 5
    // 0 index is not used
    const int numTypes = 6; 
    
    vector<int> count(numTypes, 0);

    // count every type of bird
    for (int birdType : arr) {
        count[birdType]++;
    }

    // find the most frenquent
    int maxCount = 0, maxNum = 0;
    for (int i = 1; i < numTypes; ++i) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            maxNum = i;
        }
    }

    return maxNum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

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

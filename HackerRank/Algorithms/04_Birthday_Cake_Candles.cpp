/**
 * @file 04_Birthday_Cake_Candles.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Prepare > Algorithms > Warmup > Birthday Cake Candles
 * @version 0.1
 * @date 2024-01-07
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
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

int birthdayCakeCandles(vector<int> candles) {
    int n = 0, count = 0;
    long max = 0;
    n = candles.size();
    while (n-- >= 0) {
        if (candles[n] > max) {
            max = candles[n];
            count = 0;
        }
        if (candles[n] == max) {
            count ++;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string candles_count_temp;
    getline(cin, candles_count_temp);

    int candles_count = stoi(ltrim(rtrim(candles_count_temp)));

    string candles_temp_temp;
    getline(cin, candles_temp_temp);

    vector<string> candles_temp = split(rtrim(candles_temp_temp));

    vector<int> candles(candles_count);

    for (int i = 0; i < candles_count; i++) {
        int candles_item = stoi(candles_temp[i]);

        candles[i] = candles_item;
    }

    int result = birthdayCakeCandles(candles);

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

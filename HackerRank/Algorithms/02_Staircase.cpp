/**
 * @file 02_Staircase.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Prepare > Algorithms > Warmup > Staircase
 * @version 0.1
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    for (int i = 0; i < n; i++){
        int spaceNum = 0;
        spaceNum = n - i - 1;
        for (int j = 0; j < spaceNum; j++) {
            cout << ' ';
        }
        for (int k = 0; k < n - spaceNum; k++) {
            cout << '#';
        }
        cout << '\n';
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    staircase(n);

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

/**
 * @file 16_Day_of_the_Programmer.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-07
 * Prepare > Algorithms > Implementation > Day of the Programmer
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    {
        if (year == 1918) {
            return "26.09.1918"; // 根據題目描述，1918年的日期是特例
        } else if ((year < 1918 && year % 4 == 0) || (year > 1918 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))) {
            return "12.09." + to_string(year); // 儒略曆閏年
        } else {
            return "13.09." + to_string(year); // 格里曆閏年或平年
        }
    }
    // bool isLeap = false;
    // string result;
    // // leap year if perfectly divisible by 400
    // // if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
    // //     isLeap = true;
    // // }
    // if (year < 1918 && year % 4 == 0) {
    //     isLeap = true;
    //     result = "12.09." + to_string(year);
    // }
    // else if (year == 1918) {
    //     result = "26.09." + to_string(year);
    // }
    // else if (year > 1918 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))) {
    //     isLeap = true;
    //     result = "12.09." + to_string(year);
    // }
    // else {
    //     result = "13.09." + to_string(year);
    // }

    // return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
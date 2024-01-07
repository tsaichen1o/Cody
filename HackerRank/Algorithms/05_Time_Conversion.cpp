/**
 * @file 05_Time_Conversion.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Prepare > Algorithms > Warmup > Time Conversion
 * @version 0.1
 * @date 2024-01-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
// string timeConversion(string s) {
//     if (s.substr(8, 2) == "PM") {
//         int hours = stoi(s.substr(0, 2));
//         if (hours != 12) {
//             hours += 12;
//         }
//         return to_string(hours) + s.substr(2, 6);
//     } else {
//         if (s.substr(0, 2) == "12") {
//             return "00" + s.substr(2, 6);
//         }
//         return s.substr(0, 8);
//     }
// }
string timeConversion(string s) {
    int hours = stoi(s.substr(0, 2));
    bool isPM = (s.substr(8, 2) == "PM");

    if (isPM && hours != 12) {
        hours += 12;
    } else if (!isPM && hours == 12) {
        hours = 0;
    }

    return (hours < 10 ? "0" : "") + to_string(hours) + s.substr(2, 6);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

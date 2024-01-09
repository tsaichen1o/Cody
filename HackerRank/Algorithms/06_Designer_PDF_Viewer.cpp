/**
 * @file 06_Designer_PDF_Viewer.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Prepare > Algorithms > Implementation > Designer PDF Viewer
 * @version 0.1
 * @date 2024-01-09
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
 * Complete the 'designerPdfViewer' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h
 *  2. STRING word
 */

// try01: self
// int designerPdfViewer(vector<int> h, string word) {
//     int n = 0, max = 0, maxIndex = 0, area = 0;
//     // map<string, int> m;
//     n = word.length();
//     for (int i = 0; i < n; i++) {
//         if(h[(int)word[i] - 97] > max) {
//             max = h[(int)word[i] - 97];
//             maxIndex = (int)word[i] - 97;
//         }
//     }
//     area = n * max;
//     return area;
// }

// try02
// int designerPdfViewer(vector<int> h, string word) {
//     int maxHeight = 0;
//     for (char c : word) {
//         int height = h[c - 'a'];
//         if (height > maxHeight) {
//             maxHeight = height;
//         }
//     }
//     int area = maxHeight * word.length();
//     return area;
// }

// try02: map
int designerPdfViewer(vector<int> h, string word) {
    // use map to store the height of each letter
    map<char, int> charToHeight; 
    for (char c = 'a'; c <= 'z'; ++c) {
        charToHeight[c] = h[c - 'a'];
    }

    int maxHeight = 0;
    for (char c : word) {
        int height = charToHeight[c];
        if (height > maxHeight) {
            maxHeight = height;
        }
    }

    int area = maxHeight * word.length();
    return area;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(26);

    for (int i = 0; i < 26; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    string word;
    getline(cin, word);

    int result = designerPdfViewer(h, word);

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
/**
 * @file 07_Grading_Students.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Prepare > Algorithms > Implementation > Grading Students
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades) {
    int n = 0;
    n = grades.size();
    for (int i = 0; i < n; i++) {
        int roundNumber = 0, roundTime = 0;
        if (grades[i] % 5 != 0 && grades[i] > 37) {
            roundTime = ceil(static_cast<float>(grades[i]) / 5);
            roundNumber = roundTime * 5;
        }
        else {
            roundNumber = grades[i];
        }
        if (roundNumber - grades[i] < 3) {
            grades[i] = roundNumber;
        }
        else {
            grades[i] = grades[i];
        }
    }
    return grades;
}

vector<int> gradingStudents(vector<int> grades) {
    int n = grades.size();
    for (int i = 0; i < n; i++) {
        int grade = grades[i];
        if (grade >= 38) { 
            /* 只有當成績大於等於38時才需要進行四捨五入 */
            int nextMultipleOf5 = ((grade + 4) / 5) * 5; 
            /* 計算下一個5的倍數 */
            if (nextMultipleOf5 - grade < 3) {
                grades[i] = nextMultipleOf5; 
                /* 進行四捨五入 */
            }
        }
    }
    return grades;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
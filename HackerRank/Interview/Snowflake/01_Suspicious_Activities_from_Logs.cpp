/**
 * @file 01_Suspicious_Activities_from_Logs.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Suspicious_Activities_from_Logs
 * @version 0.1
 * @date 2024-11-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> processLogs(vector<string> logs, int threshold) {
    unordered_map<string, int> userTransactionCount;

    // Process the logs to count each user's transactions
    for (string log : logs) {
        stringstream ss(log);
        string sender, receiver, amount;
        ss >> sender >> receiver >> amount;

        // Increase transaction count for the sender
        userTransactionCount[sender]++;

        // Increase transaction count for the receiver if they are different
        if (sender != receiver) {
            userTransactionCount[receiver]++;
        }
    }

    // Collect user IDs that meet or exceed the threshold
    vector<string> result;
    for (const auto& pair : userTransactionCount) {
        string user = pair.first;
        int count = pair.second;
        if (count >= threshold) {
            result.push_back(user);
        }
    }

    // Sort result in ascending order by numeric value
    sort(result.begin(), result.end(), [](const string &a, const string &b) {
        return stoi(a) < stoi(b);
    });

    return result;
}

int main() {
    vector<string> logs = {"88 99 200", "88 99 300", "99 32 100", "12 15 1"};
    int threshold = 2;
    vector<string> result = processLogs(logs, threshold);

    for (string user : result) {
        cout << user << endl;
    }

    return 0;
}

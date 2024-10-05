/**
 * @file 20241004_2491.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2491. Divide Players Into Teams of Equal Skill
 * @version 0.1
 * @date 2024-10-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        long long totalChemistry = 0;
        int target = skill[0] + skill[n - 1];
        
        for (int i = 0; i < n / 2; i++) {
            if (skill[i] + skill[n - i - 1] != target) {
                return -1;  // If any pair doesn't meet the target sum, return -1
            }
            totalChemistry += skill[i] * skill[n - i - 1];
        }
        
        return totalChemistry;
    }
};


// wrong answer

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        // unordered_map<int, int> numMap;
        int n = skill.size();
        int sum = 0;
        for (int& num : skill) {
            sum += num;
        }
        if (sum % 2 != 0) return -1;

        int target = sum * 2 / n;
        int tempSum = 0;
        cout << target << endl;
        for (int i = 0; i < n / 2; i++) {
            cout << skill[i] << ' ' << skill[n - i - 1] << endl;
            if (skill[i] + skill[n - i] != target) {
                tempSum = -1;
                // break;
            } else {
                tempSum += skill[i] * skill[n - i];
                cout << tempSum << ' ' << endl;
            }
        }

        return tempSum;
    }
};
/**
 * @file 20240905_2028.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2028. Find Missing Observations
 * @version 0.1
 * @date 2024-09-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
 * @file 20240905_2028.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2028. Find Missing Observations
 * @version 0.1
 * @date 2024-09-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> vect(n, 0);
        int sumOfRolls = 0, missSumOfRolls = 0, tempN = 0;
        sumOfRolls = accumulate(rolls.begin(), rolls.end(), sumOfRolls);
        missSumOfRolls = mean * (rolls.size() + n) - sumOfRolls;
        if (missSumOfRolls < n || missSumOfRolls > 6 * n) {
            return {};
        }
        tempN = n;
        for (int i = 0; i < n; i++) {
            vect[i] = missSumOfRolls / tempN;
            missSumOfRolls -= vect[i];
            tempN -= 1;
            cout << missSumOfRolls << endl;
        }
        return vect;
    }
};

// memory good
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // Calculate the sum of the known rolls
        int sumOfRolls = accumulate(rolls.begin(), rolls.end(), 0);

        // Calculate the missing sum
        int totalSum = mean * (rolls.size() + n);
        int missSumOfRolls = totalSum - sumOfRolls;

        // If the missing sum is not possible to distribute, return an empty vector
        if (missSumOfRolls < n || missSumOfRolls > 6 * n) {
            return {};
        }

        // Create a vector to store the result, initialized with 1's
        vector<int> result(n, 1);
        missSumOfRolls -= n;  // Initially allocate 1 to each dice, so subtract n from the sum

        // Distribute the remaining sum across the result
        for (int i = 0; i < n && missSumOfRolls > 0; i++) {
            int add = min(5, missSumOfRolls);  // We can add at most 5 (since each dice can be at most 6)
            result[i] += add;
            missSumOfRolls -= add;
        }

        return result;
    }
};

// time good
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // Calculate sum of known rolls
        int sumOfRolls = 0;
        for (int roll : rolls) {
            sumOfRolls += roll;
        }

        // Calculate the missing sum
        int totalSum = mean * (rolls.size() + n);
        int missSumOfRolls = totalSum - sumOfRolls;

        // If the missing sum is out of bounds, return an empty vector
        if (missSumOfRolls < n || missSumOfRolls > 6 * n) {
            return {};
        }

        // Allocate result vector and distribute the missing sum
        vector<int> result(n, 1);
        missSumOfRolls -= n;  // Allocate 1 to each initially

        // Distribute the remaining sum
        for (int i = 0; i < n && missSumOfRolls > 0; ++i) {
            int add = min(5, missSumOfRolls);  // Each dice can be increased by at most 5
            result[i] += add;
            missSumOfRolls -= add;
        }

        return result;
    }
};

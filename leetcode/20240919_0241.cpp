/**
 * @file 20240919_0241.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 241. Different Ways to Add Parentheses
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/*
Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            res.push_back(l + r);
                        } else if (c == '-') {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        return res;
    }
};

/*
we can store the results of subexpressions in a memoization table. By caching results, we can significantly reduce redundant calculations and bring the time complexity closer to polynomial.
*/
class Solution {
public:
    unordered_map<string, vector<int>> memo;
    
    vector<int> diffWaysToCompute(string expression) {
        // If the result is already computed for this expression, return it
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        
        vector<int> res;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                // Split the expression into left and right subexpressions
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                
                // Combine the results from left and right subexpressions
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            res.push_back(l + r);
                        } else if (c == '-') {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }
        
        // If the result is a number and no operators were found, add the number
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        
        // Store the result in the memoization table
        memo[expression] = res;
        return res;
    }
};
// 100%
class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(const string& expression) {
        return compute(expression, 0, expression.size());
    }

private:
    vector<int> compute(const string& expression, int start, int end) {
        // Generate a unique key for memoization based on start and end indices
        string key = expression.substr(start, end - start);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        vector<int> res;
        for (int i = start; i < end; ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                // Compute left and right parts without creating new substrings
                vector<int> left = compute(expression, start, i);
                vector<int> right = compute(expression, i + 1, end);

                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            res.push_back(l + r);
                        } else if (c == '-') {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If res is empty, it means the expression is a single number
        if (res.empty()) {
            res.push_back(stoi(expression.substr(start, end - start)));
        }

        memo[key] = res;
        return res;
    }
};

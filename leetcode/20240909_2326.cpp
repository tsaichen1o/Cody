/**
 * @file 20240909_2326.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2326. Spiral Matrix IV
 * @version 0.1
 * @date 2024-09-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
        // Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]; Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
        // Input: m = 1, n = 4, head = [0,1,2]; Output: [[0,1,2,-1]]
        vector<vector<int>> res(m, vector<int>(n, -1));
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = 0, k = 0, d = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (k < nums.size()) {
            res[i][j] = nums[k++];
            int ni = i + dirs[d][0], nj = j + dirs[d][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || res[ni][nj] != -1) {
                d = (d + 1) % 4;
                ni = i + dirs[d][0];
                nj = j + dirs[d][1];
            }
            i = ni;
            j = nj;
        }
        return res;
    }
};
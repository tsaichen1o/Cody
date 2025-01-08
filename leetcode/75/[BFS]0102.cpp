/**
 * @file [BFS]0102.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 102. Binary Tree Level Order Traversal
 * @version 0.1
 * @date 2024-11-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> level;
        level.push(root);

        while (!level.empty() && root) {
            int n = level.size();
            vector<int> new_level;
            for (int i = 0; i < n; i++) {
                TreeNode* node = level.front();
                new_level.emplace_back(node -> val);
                // you should add the left child first, then the right child, so that the nodes are visited from left to right.
                if (node -> left) level.push(node -> left);
                if (node -> right) level.push(node -> right);
                level.pop();
            }
            res.emplace_back(new_level.begin(), new_level.end());
        }

        return res;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
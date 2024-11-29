/**
 * @file [BFS]0199.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 199. Binary Tree Right Side View
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res; // If root is null, return an empty vector

        queue<TreeNode*> level;
        level.push(root);

        while (!level.empty()) {
            int n =
                level.size(); // Get the number of nodes at the current level

            for (int i = 0; i < n; i++) {
                TreeNode* node = level.front(); // Access the front node
                if (i == n - 1) // If it's the last node of the level
                    res.push_back(node->val); // Add it to the result

                if (node->left) // Add left child to the queue
                    level.push(node->left);
                if (node->right) // Add right child to the queue
                    level.push(node->right);

                level.pop(); // Remove the processed node
            }
        }

        return res;
    }
};

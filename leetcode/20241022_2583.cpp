/**
 * @file 20241022_2583.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2583. Kth Largest Sum in a Binary Tree
 * @version 0.1
 * @date 2024-10-22
 * https://algo.monster/liteproblems/2583
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
    // Function to find the kth largest sum of a level in a binary tree.
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // Initialize a vector to store the sum of each level.
        vector<long long> levelSums;

        // Queue for level order traversal.
        queue<TreeNode*> queue;
        queue.push(root);

        // Perform level order traversal to calculate the sum of each level.
        while (!queue.empty()) {
            // Temporary variable to hold the sum of the current level.
            long long sumOfCurrentLevel = 0;

            // Go through all nodes at the current level.
            for (int levelSize = queue.size(); levelSize > 0; --levelSize) {
                // Get the next node in the queue.
                root = queue.front();
                queue.pop();

                // Add the node's value to the sum of the current level.
                sumOfCurrentLevel += root->val;

                // Add left and right children if they exist.
                if (root->left) {
                    queue.push(root->left);
                }
                if (root->right) {
                    queue.push(root->right);
                }
            }

            // Store the sum of the current level in the vector.
            levelSums.push_back(sumOfCurrentLevel);
        }

        // If there are fewer levels than k, return -1 as it's not possible to find the kth largest level sum.
        if (levelSums.size() < k) {
            return -1;
        }

        // Sort the vector in descending order to find the kth largest level sum.
        sort(levelSums.rbegin(), levelSums.rend());

        // Return the kth largest level sum.
        return levelSums[k - 1];
    }
};
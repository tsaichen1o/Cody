/**
 * @file [BFS]1161.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1161. Maximum Level Sum of a Binary Tree
 * @version 0.1
 * @date 2024-11-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        int maxSum = INT_MIN, maxLevel = 0, currentLevel = 1;
        queue<TreeNode*> level;
        level.push(root);

        while (!level.empty()) {
            int n = level.size();
            int tempSum = 0;

            // Calculate the sum of the current level
            for (int i = 0; i < n; i++) {
                TreeNode* node = level.front();
                level.pop();
                tempSum += node->val;

                // Push left and right children to the queue
                if (node->left) level.push(node->left);
                if (node->right) level.push(node->right);
            }

            // Update the maximum sum and corresponding level
            if (tempSum > maxSum) {
                maxSum = tempSum;
                maxLevel = currentLevel;
            }

            currentLevel++;
        }

        return maxLevel;
    }
};

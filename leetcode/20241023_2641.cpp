/**
 * @file 20241023_2641.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2641. Cousins in Binary Tree II
 * @version 0.1
 * @date 2024-10-23
 * https://github.com/doocs/leetcode/blob/main/solution/2600-2699/2641.Cousins%20in%20Binary%20Tree%20II/README_EN.md
 * https://algo.monster/liteproblems/2641
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        memset(s, 0, sizeof(s));
        dfs1(root, 0);
        root->val = 0;
        dfs2(root, 0);
        return root;
    }

private:
    int s[100010];
    void dfs1(TreeNode* root, int depth) {
        if (!root) {
            return;
        }
        s[depth] += root->val;
        dfs1(root->left, depth + 1);
        dfs1(root->right, depth + 1);
    };

    void dfs2(TreeNode* root, int depth) {
        int l = root->left ? root->left->val : 0;
        int r = root->right ? root->right->val : 0;
        int sub = l + r;
        ++depth;
        if (root->left) {
            root->left->val = s[depth] - sub;
            dfs2(root->left, depth);
        }
        if (root->right) {
            root->right->val = s[depth] - sub;
            dfs2(root->right, depth);
        }
    };
};
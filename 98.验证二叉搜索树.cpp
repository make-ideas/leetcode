/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
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
bool isBSTUtil(TreeNode* root, long long& prev) {
    if (root) {
        if (!isBSTUtil(root->left, prev)) {
            return false;
        }

        if (root->val <= prev) {
            return false;
        }
        
        prev = root->val;

        return isBSTUtil(root->right, prev);
    }
    return true;
}

public:
    bool isValidBST(TreeNode* root) {
        long long prev = LONG_MIN;
        return isBSTUtil(root, prev);
    }
};
// @lc code=end


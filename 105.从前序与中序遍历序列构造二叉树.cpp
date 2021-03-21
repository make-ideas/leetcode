/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, INT_MIN);
    }
private:
    int pre = 0;
    int in = 0;
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int stop) {
        if (pre == preorder.size()) return nullptr;
        // 到达停止点返回NULL，in后移
        if (inorder[in] == stop) {
            in++;
            return nullptr;
        }
        int root_val = preorder[pre++];
        TreeNode* root = new TreeNode(root_val);
        //左子树的停止点是当前的根节点
        root->left = buildTreeHelper(preorder,  inorder, root_val);
        //右子树的停止点是当前树的停止点
        root->right = buildTreeHelper(preorder, inorder, stop);
        return root;
    }
};

// @lc code=end


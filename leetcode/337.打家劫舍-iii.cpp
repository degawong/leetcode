/*
 * @Author: your name
 * @Date: 2020-10-27 14:16:22
 * @LastEditTime: 2020-10-27 14:34:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\337.打家劫舍-iii.cpp
 */
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
		if(root == nullptr) return 0;
		if(root->left == nullptr && root->right == nullptr) return root->val;
		if(root->left == nullptr)
            return max(rob(root->right), root->val + rob(root->right->left) + rob(root->right->right));
		if(root->right == nullptr) return max(root->val + rob(root->left->left) + rob(root->left->right));
		return root->val + rob(root->right->left) + rob(root->right->right) + rob(root->left->left) + rob(root->left->right);
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-11-09 16:57:07
 * @LastEditTime: 2020-11-09 17:04:31
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\700.二叉搜索树中的搜索.cpp
 */
/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode* searchBST(TreeNode* root, int val) {
		auto ret = root;
		if(root == nullptr || root->val == val) return ret;
		if(root->val > val) ret = searchBST(root->left, val);
		else ret = searchBST(root->right, val);
		return ret;
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-10-29 15:34:15
 * @LastEditTime: 2020-10-29 17:53:11
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\687.最长同值路径.cpp
 */
/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int longestUnivaluePath(TreeNode* root) {
		if(root == nullptr) return 0;
		return univalue_path(root, root->val);
    }
private:
	int univalue_path(TreeNode* root, int value) {
		int ret = 0;
		int left = 0;
		int right = 0;
		if(root == nullptr) return 0;
		if(root->left == nullptr && root->right == nullptr) return 0;
		if(root->left == nullptr) {
			if(root->val == root->right->val) left = 1;
			ret = max(ret, left + univalue_path(root->right, value));
		} else if(root->right == nullptr) {
			if(root->val == root->left->val) right = 1;
			ret = max(ret, right + univalue_path(root->left, value));
		} else {
			if(root->val == root->right->val) left = 1;
			ret = max(ret, left + univalue_path(root->right, value));
			if(root->val == root->left->val) right = 1;
			ret = max(ret, right + univalue_path(root->left, value));						
		}
		return ret;
	}
};
// @lc code=end


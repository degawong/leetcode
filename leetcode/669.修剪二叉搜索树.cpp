/*
 * @Author: your name
 * @Date: 2020-10-29 14:15:30
 * @LastEditTime: 2020-11-09 16:54:01
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\669.修剪二叉搜索树.cpp
 */
/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
		return dfs(root, low, high);
    }
private:
	bool to_trim(int val, int low, int high) {
		return (val < low || val > high);
	}
	// root  shall not be nullptr
	TreeNode* dfs(TreeNode* root, int low, int high) {
		auto ret = root;
		if(root == nullptr) return ret;
		if(root->val > high) {
			ret = dfs(root->left, low, high);
		} else if(root->val < low) {
			ret = dfs(root->right, low, high);
		} else {
			root->left = dfs(root->left, low, high);
			root->right = dfs(root->right, low, high);
			ret = root;
		}
		return ret;
	}
};
// @lc code=end


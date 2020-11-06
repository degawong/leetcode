/*
 * @Author: your name
 * @Date: 2020-10-27 16:42:57
 * @LastEditTime: 2020-10-27 16:51:31
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\530.二叉搜索树的最小绝对差.cpp
 */
/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
		int ret = INT_MAX;
		inorder(root);
		for(int i = 0; i < v.size() - 1; ++i) {
			auto temp = v[i + 1]->val - v[i]->val;
			if(ret > temp) ret = temp;
		}
		return ret;
    }
private:
	void inorder(TreeNode* node) {
		if(node == nullptr) return;
		inorder(node->left);
		v.push_back(node);
		inorder(node->right);
	}
private:
	vector<TreeNode*> v;
};
// @lc code=end


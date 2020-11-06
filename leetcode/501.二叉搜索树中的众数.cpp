/*
 * @Author: your name
 * @Date: 2020-10-27 15:47:03
 * @LastEditTime: 2020-10-27 15:55:50
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\501.二叉搜索树中的众数.cpp
 */
/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode* root) {
		max = 0;
		vector<int> ret;
		preorder(root);
		for(auto& u : um) {
			if(u.second == max)
				ret.push_back(u.first);
		}
		return ret;
    }
private:
	void preorder(TreeNode* root) {
		if(root == nullptr) return;
		++um[root->val];
		if(max < um[root->val])
			max = um[root->val];
		preorder(root->left);
		preorder(root->right);
	}
private:
	int max;
	unordered_map<int, int> um;
};
// @lc code=end


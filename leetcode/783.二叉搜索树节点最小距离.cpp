/*
 * @Author: your name
 * @Date: 2020-11-09 17:37:25
 * @LastEditTime: 2020-11-09 18:01:46
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\783.二叉搜索树节点最小距离.cpp
 */
/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    int minDiffInBST(TreeNode* root) {
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


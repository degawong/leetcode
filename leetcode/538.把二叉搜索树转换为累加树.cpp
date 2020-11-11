/*
 * @Author: your name
 * @Date: 2020-10-27 16:57:41
 * @LastEditTime: 2020-11-11 16:26:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\538.把二叉搜索树转换为累加树.cpp
 */
/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
		sum.push(0);
		dfs(root);
		auto v = sum.top();
		while(!stk.empty()) {
			auto t = stk.top();
			stk.pop();
			auto s = sum.top();
			sum.pop();
			t->val = v - s + t->val;
		}
		return root;
    }
private:
	void dfs(TreeNode* root) {
		if(root == nullptr) return;
		dfs(root->left);
		auto t = sum.top();
		sum.push(t + root->val);
		stk.push(root);
		dfs(root->right);
	}
private:
	stack<int> sum;
	stack<TreeNode*> stk;
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-10-27 09:32:54
 * @LastEditTime: 2020-10-27 09:44:40
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\129.求根到叶子节点数字之和.cpp
 */
/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int sumNumbers(TreeNode* root) {
		ret = 0;
		dfs(root, 0);
		return ret;
    }
private:
	void dfs(TreeNode* node, int carry) {
		if(node == nullptr) return;
		if(node->left == nullptr && node->right == nullptr) {
			ret = ret + 10 * carry + node->val;
		}
		dfs(node->left, 10 * carry + node->val);
		dfs(node->right, 10 * carry + node->val);
	}
private:
	int ret;
};
// @lc code=end


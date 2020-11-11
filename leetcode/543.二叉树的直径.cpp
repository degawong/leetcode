/*
 * @Author: your name
 * @Date: 2020-11-10 16:22:32
 * @LastEditTime: 2020-11-10 16:43:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\543.二叉树的直径.cpp
 */
/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        ret = 0;
        dfs(root);
        return ret;
    }
private:
	int ret;
	int dfs(TreeNode* root) {
		if(root == nullptr) return 0;
		auto l = dfs(root->left);
		auto r = dfs(root->right);
		ret = max(ret, l + r);
		return 1 + max(l, r);
	}
};
// @lc code=end


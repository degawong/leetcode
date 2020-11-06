/*
 * @Author: your name
 * @Date: 2020-10-27 17:52:55
 * @LastEditTime: 2020-10-28 08:36:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\563.二叉树的坡度.cpp
 */
/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int findTilt(TreeNode* root) {
		int ret = 0;
        if(root == nullptr) return ret;
        if(root->left == nullptr && root->right == nullptr) return ret;
		if(root->left == nullptr) { ret = abs(__sum_node(root->right)); }
		else if(root->right == nullptr) { ret = abs(__sum_node(root->left)); }
		else ret = abs(__sum_node(root->left) - __sum_node(root->right));
		return ret + findTilt(root->left) + findTilt(root->right);
    }
private:
	int __sum_node(TreeNode* node) {
		if(node == nullptr) return 0;
		return node->val + __sum_node(node->left) + __sum_node(node->right);
	}
};
// @lc code=end


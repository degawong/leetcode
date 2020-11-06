/*
 * @Author: your name
 * @Date: 2020-10-26 16:09:37
 * @LastEditTime: 2020-11-05 17:13:51
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\114.二叉树展开为链表.cpp
 */
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
		deque<TreeNode*> dq;
		if(root == nullptr) return;
		auto node = root;
		dq.push_back(node);
		auto recorder = (TreeNode*)nullptr;
		while (!dq.empty()) {
			auto node = dq.back(); 
			dq.pop_back();
			if(recorder != nullptr) {
				recorder->left = nullptr;
				recorder->right = node;
			}
			if(node->right != nullptr) dq.push_back(node->right);
			if(node->left != nullptr) dq.push_back(node->left);
			recorder = node;
		}
    }
};
// @lc code=end


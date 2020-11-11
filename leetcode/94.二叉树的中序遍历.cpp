/*
 * @Author: your name
 * @Date: 2020-11-11 10:38:01
 * @LastEditTime: 2020-11-11 10:57:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\94.二叉树的中序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
		stack<TreeNode*> stk;
		stk.push(root);
        if(root == nullptr) return ret;
		while(!stk.empty()) {
			auto node = stk.top();
			if(node == nullptr) {
				stk.pop();
				auto n = stk.top();
				stk.pop();
				ret.push_back(n->val);
			} else {
				stk.pop();
				if(node->right != nullptr) stk.push(node->right);
				stk.push(node);
				stk.push(nullptr);
				if(node->left != nullptr) stk.push(node->left);
			}
		}
		return ret;
    }
};
// @lc code=end


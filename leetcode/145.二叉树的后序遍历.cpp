/*
 * @Author: your name
 * @Date: 2020-11-11 11:07:53
 * @LastEditTime: 2020-11-11 11:11:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\145.二叉树的后序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
		stack<TreeNode*> stk;
        if(root == nullptr) return ret;
        stk.push(root);
		while(!stk.empty()) {
			auto node = stk.top();
			if(node == nullptr) {
				stk.pop();
				auto n = stk.top();
				stk.pop();
				ret.push_back(n->val);
			} else {
				stk.pop();            
				stk.push(node);                
				stk.push(nullptr);                
				if(node->right != nullptr) stk.push(node->right);
				if(node->left != nullptr) stk.push(node->left);            
			}
		}
		return ret; 
    }
};
// @lc code=end


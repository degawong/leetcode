/*
 * @Author: your name
 * @Date: 2020-11-12 13:34:50
 * @LastEditTime: 2020-11-12 14:29:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\1305.两棵二叉搜索树中的所有元素.cpp
 */
/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> ret;
		queue<int> in1;
		queue<int> in2;
		stack<TreeNode*> q1;
		stack<TreeNode*> q2;
		if(root1 != nullptr) q1.push(root1);
		if(root2 != nullptr) q2.push(root2);
		while(!q1.empty()) {			
			auto node = q1.top();			
			if(node == nullptr) {
				q1.pop();
				auto vn = q1.top();
				q1.pop();
				in1.push(vn->val);
			} else {
				q1.pop();
				if(node->right != nullptr)  q1.push(node->right);
				q1.push(node);
				q1.push(nullptr);
				if(node->left != nullptr)  q1.push(node->left);
			}
		}
		while(!q2.empty()) {			
			auto node = q2.top();
			if(node == nullptr) {
				q2.pop();
				auto vn = q2.top();
				q2.pop();
				in2.push(vn->val);
			} else {
				q2.pop();
				if(node->right != nullptr)  q2.push(node->right);
				q2.push(node);
				q2.push(nullptr);
				if(node->left != nullptr)  q2.push(node->left);
			}
		}
		while(!in1.empty() || !in2.empty()) {
			if(in1.empty()) {
				ret.push_back(in2.front());
				in2.pop();
			} else if(in2.empty()) {
				ret.push_back(in1.front());
				in1.pop();
			} else {
				if(in1.front() > in2.front()) {
					ret.push_back(in2.front());
					in2.pop();
				} else {
					ret.push_back(in1.front());
					in1.pop();
				}
			}
		}
		return ret;
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-11-11 10:59:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0094\0094.hpp
 */

#include <cmath>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// 	// recursive
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ret;
// 		inorder(root, ret);
// 		return ret;
//     }
// private:
// 	void inorder(TreeNode* root, vector<int>& v) {
// 		if(root == nullptr) return;
// 		inorder(root->left, v);
// 		v.push_back(root->val);
// 		inorder(root->right, v);
// 	}
// };

class Solution {
	// recursive
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

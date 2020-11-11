/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-11-11 11:07:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0144\0144.hpp
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
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
		preorder(root, ret);
		return ret;
    }
private:
	void preorder(TreeNode* root, vector<int>& v) {
		if(root == nullptr) return;
		v.push_back(root->val);
		preorder(root->left, v);
		preorder(root->right, v);
	}	
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
				if(node->right != nullptr) stk.push(node->right);
				if(node->left != nullptr) stk.push(node->left);
				stk.push(node);
				stk.push(nullptr);                
			}
		}
		return ret;
    }
};
/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-11-11 11:17:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0145\0145.hpp
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
		post_order(root, ret);
		return ret;
    }
private:
	void post_order(TreeNode* root, vector<int>& v) {
		if(root == nullptr) return;
		post_order(root->left, v);
		post_order(root->right, v);
		v.push_back(root->val);		
	}
};

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
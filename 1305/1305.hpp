/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:33
 * @LastEditTime: 2020-11-12 14:29:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\1305\1305.hpp
 */

#include <cmath>
#include <queue>
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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
private:
	// void dfs(TreeNode* root1, TreeNode* root2) {
	// 	if(root1 == nullptr && root2 == nullptr) return;
	// 	if(root1 == nullptr) {
	// 		dfs(nullptr, root2->left);
	// 		ret.push_back(root2->val);
	// 		dfs(nullptr, root2->right);
	// 	} else if (root2 == nullptr) {
	// 		dfs(nullptr, root1->left);
	// 		ret.push_back(root1->val);
	// 		dfs(nullptr, root1->right);
	// 	} else {
			
	// 	}
	// }
	// vector<int> ret;
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:32
 * @LastEditTime: 2020-11-11 16:31:50
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\1038\1038.hpp
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
    TreeNode* bstToGst(TreeNode* root) {
		sum.push(0);
		dfs(root);
		auto v = sum.top();
		while(!stk.empty()) {
			auto t = stk.top();
			stk.pop();
			auto s = sum.top();
			sum.pop();
			t->val = v - s + t->val;
		}
		return root;
    }
private:
	void dfs(TreeNode* root) {
		if(root == nullptr) return;
		dfs(root->left);
		auto t = sum.top();
		sum.push(t + root->val);
		stk.push(root);
		dfs(root->right);
	}
private:
	stack<int> sum;
	stack<TreeNode*> stk;
};

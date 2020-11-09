/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-11-09 17:59:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0783\0783.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
		int ret = INT_MAX;
		inorder(root);
		for(int i = 0; i < int(v.size() - 1); ++i) {
			auto temp = v[i + 1]->val - v[i]->val;
			if(ret > temp) ret = temp;
		}
		return ret;
    }
private:
	void inorder(TreeNode* node) {
		if(node == nullptr) return;
		inorder(node->left);
		v.push_back(node);
		inorder(node->right);
	}
private:
	vector<TreeNode*> v;
};

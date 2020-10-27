/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:29
 * @LastEditTime: 2020-10-27 15:55:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0501\0501.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
		max = 0;
		vector<int> ret;
		preorder(root);
		for(auto& u : um) {
			if(u.second == max)
				ret.push_back(u.first);
		}
		return ret;
    }
private:
	void preorder(TreeNode* root) {
		if(root == nullptr) return;
		++um[root->val];
		if(max < um[root->val])
			max = um[root->val];
		preorder(root->left);
		preorder(root->right);
	}
private:
	int max;
	unordered_map<int, int> um;
};

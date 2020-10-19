/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-19 18:08:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0107\0107.hpp
 */

#include <cmath>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
		if(root == nullptr) return ret;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()) {
			auto size = q.size();
			ret.push_back(vector<int>());
			for(int i = 0; i < size; ++i) {
				auto node = q.front(); q.pop();
				ret.back().push_back(node->val);
				if(node->left != nullptr) q.push(node->left);
				if(node->right != nullptr) q.push(node->right);
			}
		}
		reverse(ret.begin(), ret.end());
		return ret;
    }
};
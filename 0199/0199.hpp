/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-21 13:45:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0199\0199.hpp
 */

#include <cmath>
#include <deque>
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
    vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		deque<TreeNode*> dq;
		vector<vector<int>> traversal;
		if(root == nullptr) return ret;
		dq.push_front(root);
		while(!dq.empty()) {
			auto size = dq.size();
			traversal.push_back(vector<int>());
			for(int i = 0; i < size; ++i) {
				auto node = dq.back(); dq.pop_back();
				traversal.back().push_back(node->val);
				if(node->right != nullptr)
					dq.push_front(node->right);
				if(node->left != nullptr)
					dq.push_front(node->left);
			}
		}
		for(auto level : traversal) {
			ret.push_back(level[0]);
		}
		return ret;
    }
};
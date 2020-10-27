/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:29
 * @LastEditTime: 2020-10-27 16:40:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0513\0513.hpp
 */
#include <cmath>
#include <deque>
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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
		int ret = root->val;
		deque<TreeNode*> dq;
		dq.push_back(root);
		while(!dq.empty()) {
			auto size = dq.size();
			for(int i = 0; i < size; ++i) {
				auto node = dq.front();
				dq.pop_front();
				if(node->right != nullptr) {
					ret = node->right->val;
					dq.push_back(node->right);
				}				
				if(node->left != nullptr) {
					ret = node->left->val;
					dq.push_back(node->left);
				}
			}
		}
		return ret;
    }
};

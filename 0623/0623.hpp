/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-10-28 16:36:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0623\0623.hpp
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
		int level = 0;
		deque<TreeNode*> dq;
		dq.push_back(root);
        if(d == 1) {
            auto left = root;
            root = new TreeNode(v);
            root->left = left;
            return root;
        }
		while(!dq.empty()) {
			auto size = dq.size();
			if(++level == d - 1) {
				for(int i = 0; i < size; ++i) {
					auto node = dq.front();
					dq.pop_front();
					auto left = node->left;
					auto right = node->right;
					node->left = new TreeNode(v);
					node->right = new TreeNode(v);
					node->left->left = left;
					node->right->right = right;
				}
				return root;
			} else {
				for(int i = 0; i < size; ++i) {
					auto node = dq.front();
					dq.pop_front();
					if(node->left != nullptr) dq.push_back(node->left);
					if(node->right != nullptr) dq.push_back(node->right);
				}
			}
		}
		return root;
    }
};

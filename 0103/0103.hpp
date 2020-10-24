/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-19 16:41:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0103\0103.hpp
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
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> q;
		vector<vector<int>> ret;
		if(root == nullptr) return ret;
		q.push_back(root);
		bool zigzag_order = false;
		while(!q.empty()) {
			auto size = q.size();
			TreeNode* node = nullptr;
			ret.push_back(vector<int>());
			for(int i = 0; i < size; ++i) {
				if(zigzag_order) {
					node = q.back(); q.pop_back();
					if(node->right != nullptr) q.push_front(node->right);					
					if(node->left != nullptr) q.push_front(node->left);
				} else {
					node = q.front(); q.pop_front();
					if(node->left != nullptr) q.push_back(node->left);
					if(node->right != nullptr) q.push_back(node->right);
				}
				ret.back().push_back(node->val);
			}
			zigzag_order = !zigzag_order;
		}
		return ret;
    }
};
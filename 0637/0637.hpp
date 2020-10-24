/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-10-21 15:46:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0637\0637.hpp
 */

#include <cmath>
#include <queue>
#include <string>
#include <vector>
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
	// BFS
    vector<double> averageOfLevels(TreeNode* root) {
		queue<TreeNode*> q;
		vector<double> ret;
		if(root == nullptr) return ret;
		q.push(root);
		while(!q.empty()) {
			double sum = 0;
			auto size = q.size();
			for(int i = 0; i < size; ++i) {
				auto node = q.front(); q.pop();
				sum += node->val;
				if(node->left != nullptr) q.push(node->left);
				if(node->right != nullptr) q.push(node->right);
			}
			ret.push_back(double(sum) / size);
		}
		return ret;
    }
};

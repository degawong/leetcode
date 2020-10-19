/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-19 15:04:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0102\0102.hpp
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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
		if(root == nullptr) return ret;
		q.push(root);
		while(!q.empty()) {
			// every level vector<int>
			ret.push_back(vector<int>());
			auto current_level_size = q.size();			
			for(int i = 1; i <= current_level_size; ++i) {
				auto node = q.front(); q.pop();
				ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
			}
		}
        return ret;
    }
};

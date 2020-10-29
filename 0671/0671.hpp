/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-10-29 15:25:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0671\0671.hpp
 */

#include <set>
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
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
		inorder(root);
		int ret = -1;
		int index = 0;
		if(s.size() == 1) return -1;
		else {
			for(auto i = s.begin(); i != s.end(); ++i) {
				if(index++ == 1) ret = *i;
			}
		}
		return ret;
    }
private:
	void inorder(TreeNode* node) {
		if(node == nullptr) return;
		inorder(node->left);
		s.insert(node->val);
		inorder(node->right);
	}
private:
	set<int> s;
};

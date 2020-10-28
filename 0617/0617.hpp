/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-10-28 11:27:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0617\0617.hpp
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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode* ret = nullptr;
		if(t1 == nullptr && t2 == nullptr) return ret;
		if(t1 == nullptr) {
			ret = t2;
			ret->left = mergeTrees(nullptr, t2->left);
			ret->right = mergeTrees(nullptr, t2->right);
		}
		else if(t2 == nullptr) {
			ret = t1;
			ret->left = mergeTrees(t1->left, nullptr);
			ret->right = mergeTrees(t1->right, nullptr);
		}
		else {
			t1->val += t2->val;
			ret = t1;
			ret->left = mergeTrees(t1->left, t2->left);
			ret->right = mergeTrees(t1->right, t2->right);
		}
		return ret;
    }
};

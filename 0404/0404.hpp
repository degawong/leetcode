/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:28
 * @LastEditTime: 2020-10-21 14:48:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0404\0404.hpp
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
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
		if(root == nullptr) return 0;
		return sumOfLeaves(root->left, true) + sumOfLeaves(root->right, false);
    }
private:
	int sumOfLeaves(TreeNode* root, bool is_left) {
		if(root == nullptr) return 0;
		if(root->left == nullptr && root->right == nullptr) {
			if(is_left) return root->val;
			else return 0;
		}
		return sumOfLeaves(root->left, true) + sumOfLeaves(root->right, false);
	}
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-11-09 17:04:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0700\0700.hpp
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
    TreeNode* searchBST(TreeNode* root, int val) {
		auto ret = root;
		if(root == nullptr || root->val == val) return ret;
		if(root->val > val) ret = searchBST(root->left, val);
		else ret = searchBST(root->right, val);
		return ret;
    }
};

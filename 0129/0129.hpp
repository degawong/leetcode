/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-27 09:44:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0129\0129.hpp
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
    int sumNumbers(TreeNode* root) {
		ret = 0;
		dfs(root, 0);
		return ret;
    }
private:
	void dfs(TreeNode* node, int carry) {
		if(node == nullptr) return;
		if(node->left == nullptr && node->right == nullptr) {
			ret = ret + 10 * carry + node->val;
		}
		dfs(node->left, 10 * carry + node->val);
		dfs(node->right, 10 * carry + node->val);
	}
private:
	int ret;
};

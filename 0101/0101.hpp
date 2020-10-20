/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-20 09:01:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0101\0101.hpp
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
    bool isSymmetric(TreeNode* root) {
        return check_symmetric(root, root);
    }
private:
	bool check_symmetric(TreeNode* left, TreeNode* right) {
		if(left == nullptr && right == nullptr) return true;
		if(left == nullptr || right == nullptr) return false;
		return (left->val == right->val) && check_symmetric(left->left, right->right) && check_symmetric(left->right, right->left);
	}
};
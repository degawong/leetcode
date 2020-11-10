/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:29
 * @LastEditTime: 2020-11-10 16:44:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0543\0543.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ret = 0;
        dfs(root);
        return ret;
    }
private:
	int ret;
	int dfs(TreeNode* root) {
		if(root == nullptr) return 0;
		auto l = dfs(root->left);
		auto r = dfs(root->right);
		ret = max(ret, l + r);
		return 1 + max(l, r);
	}
};

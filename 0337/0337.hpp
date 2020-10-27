/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:28
 * @LastEditTime: 2020-10-27 14:50:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0337\0337.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
private:
	// f current node max value
	// g current leaf node max value
    unordered_map<TreeNode*, int> f, g;
    void dfs(TreeNode* node) {
		if(node == nullptr) return;
        dfs(node->left);
        dfs(node->right);
        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }	
};

/*
 * @Author: your name
 * @Date: 2020-10-27 14:16:22
 * @LastEditTime: 2020-10-27 14:54:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\337.打家劫舍-iii.cpp
 */
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
// @lc code=end


/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
		if(root == nullptr) return new TreeNode(val);
		dfs(root, val);		
        return root;
    }
	void dfs(TreeNode* root, int val) {
		if(root->val > val) {
			if(root->left == nullptr) {
				root->left = new TreeNode(val);
			} else {
				dfs(root->left, val);
			}
		}
		if(root->val < val) {
			if(root->right == nullptr) {
				root->right = new TreeNode(val);
			} else {
				dfs(root->right, val);
			}
		}
	}
};
// @lc code=end


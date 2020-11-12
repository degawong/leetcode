/*
 * @Author: your name
 * @Date: 2020-10-27 10:16:51
 * @LastEditTime: 2020-11-12 09:47:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\230.二叉搜索树中第k小的元素.cpp
 */
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
		return v[k - 1]->val;
    }
private:
	void inorder(TreeNode* node, int k) {
		if(node == nullptr) return;
		inorder(node->left, k);
		v.push_back(node);
		if(v.size() == k) return;
		inorder(node->right, k);
	}
private:
	vector<TreeNode*> v;
};
// @lc code=end


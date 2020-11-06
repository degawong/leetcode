/*
 * @Author: your name
 * @Date: 2020-10-29 14:47:31
 * @LastEditTime: 2020-10-29 15:24:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\671.二叉树中第二小的节点.cpp
 */
/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int findSecondMinimumValue(TreeNode* root) {
		inorder(root);
		int ret = -1;
		int index = 0;
		if(s.size() == 1) return -1;
		else {
			for(auto i = s.begin(); i != s.end(); ++i) {
				if(index++ == 1) ret = *i;
			}
		}
		return ret;
    }
private:
	void inorder(TreeNode* node) {
		if(node == nullptr) return;
		inorder(node->left);
		s.insert(node->val);
		inorder(node->right);
	}
private:
	set<int> s;
};
// @lc code=end


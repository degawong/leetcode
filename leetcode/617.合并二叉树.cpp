/*
 * @Author: your name
 * @Date: 2020-10-28 10:52:05
 * @LastEditTime: 2020-10-28 11:27:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\617.合并二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode* ret = nullptr;
		if(t1 == nullptr && t2 == nullptr) return ret;
		if(t1 == nullptr) {
			ret = t2;
			ret->left = mergeTrees(nullptr, t2->left);
			ret->right = mergeTrees(nullptr, t2->right);
		}
		else if(t2 == nullptr) {
			ret = t1;
			ret->left = mergeTrees(t1->left, nullptr);
			ret->right = mergeTrees(t1->right, nullptr);
		}
		else {
			t1->val += t2->val;
			ret = t1;
			ret->left = mergeTrees(t1->left, t2->left);
			ret->right = mergeTrees(t1->right, t2->right);
		}
		return ret;
    }
};
// @lc code=end


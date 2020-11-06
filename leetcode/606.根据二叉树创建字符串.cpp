/*
 * @Author: your name
 * @Date: 2020-10-28 10:05:53
 * @LastEditTime: 2020-10-28 10:49:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\606.根据二叉树创建字符串.cpp
 */
/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    string tree2str(TreeNode* t) {
		string ret;
		if(t == nullptr) return ret;
		ret += to_string(t->val);
		if((t->right != nullptr) && (t->left == nullptr)) {
			ret += "()";
		}
		ret += node2str(t->left);
		ret += node2str(t->right);
		return ret;
    }
private:
    string node2str(TreeNode* t) {
		string ret;
		if(t == nullptr) return ret;
		ret.push_back('(');
		ret += to_string(t->val);
		if(t->left == nullptr && t->right == nullptr) {			
		}
		else if(t->left == nullptr) {
			ret += "()";
			ret += node2str(t->right);
		} else if(t->right == nullptr) {
			ret += node2str(t->left);
		} else {
			ret += node2str(t->left);
			ret += node2str(t->right);
		}
		ret.push_back(')');
		return ret;
    }
};
// @lc code=end


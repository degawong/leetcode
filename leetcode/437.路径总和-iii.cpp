/*
 * @Author: your name
 * @Date: 2020-10-27 14:57:19
 * @LastEditTime: 2020-10-27 15:15:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\437.路径总和-iii.cpp
 */
/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
public:
    int pathSum(TreeNode* root, int sum) {
		target = sum;		
		path_count = 0;
        get_path(root, sum);
		return path_count;
    }
private:
	void get_path(TreeNode* node, int sum) {
		if(node == nullptr) return;
		if(node->val == sum) {
			++path_count;
			get_path(node->left, target);
			get_path(node->right, target);
		} else {
			get_path(node->left, target);
			get_path(node->right, target);	            
			get_path(node->left, sum - node->val);
			get_path(node->right, sum - node->val);		
		}		
	}
private:
	int target;
	int path_count;
};
// @lc code=end


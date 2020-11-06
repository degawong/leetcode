/*
 * @Author: your name
 * @Date: 2020-10-28 11:28:08
 * @LastEditTime: 2020-10-28 16:36:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\623.在二叉树中增加一行.cpp
 */
/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
		int level = 0;
		deque<TreeNode*> dq;
		dq.push_back(root);
        if(d == 1) {
            auto left = root;
            root = new TreeNode(v);
            root->left = left;
            return root;
        }
		while(!dq.empty()) {
			auto size = dq.size();
			if(++level == d - 1) {
				for(int i = 0; i < size; ++i) {
					auto node = dq.front();
					dq.pop_front();
					auto left = node->left;
					auto right = node->right;
					node->left = new TreeNode(v);
					node->right = new TreeNode(v);
					node->left->left = left;
					node->right->right = right;
				}
				return root;
			} else {
				for(int i = 0; i < size; ++i) {
					auto node = dq.front();
					dq.pop_front();
					if(node->left != nullptr) dq.push_back(node->left);
					if(node->right != nullptr) dq.push_back(node->right);
				}
			}
		}
		return root;
    }
};
// @lc code=end


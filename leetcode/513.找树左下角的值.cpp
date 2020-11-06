/*
 * @Author: your name
 * @Date: 2020-10-27 16:17:55
 * @LastEditTime: 2020-10-27 16:40:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\513.找树左下角的值.cpp
 */
/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
		int ret = root->val;
		deque<TreeNode*> dq;
		dq.push_back(root);
		while(!dq.empty()) {
			auto size = dq.size();
			for(int i = 0; i < size; ++i) {
				auto node = dq.front();
				dq.pop_front();
				if(node->right != nullptr) {
					ret = node->right->val;
					dq.push_back(node->right);
				}				
				if(node->left != nullptr) {
					ret = node->left->val;
					dq.push_back(node->left);
				}
			}
		}
		return ret;
    }
};
// @lc code=end


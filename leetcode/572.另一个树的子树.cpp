/*
 * @Author: your name
 * @Date: 2020-10-28 09:41:49
 * @LastEditTime: 2020-10-28 10:04:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\572.另一个树的子树.cpp
 */
/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr) return false;
		return (isSubtree(s->left, t) || isSubtree(s->right, t)) || ((s->val == t->val) ? is_equal(s, t) : false);
    }
private:
	bool is_equal(TreeNode* s, TreeNode* t) {
		if(s == nullptr && t == nullptr) return true;
		if((s == nullptr) || (t == nullptr) || (s->val != t->val)) return false;
		return is_equal(s->left, t->left) && is_equal(s->right, t->right);
	}
};
// @lc code=end


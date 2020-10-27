/*
 * @Author: your name
 * @Date: 2020-10-27 09:49:09
 * @LastEditTime: 2020-10-27 10:13:48
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\173.二叉搜索树迭代器.cpp
 */
/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
		inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
		auto node = q.front();
		q.pop_front();
		return node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
		return !q.empty();
    }
private:
	void inorder(TreeNode* node) {
		if(node == nullptr) return;
		inorder(node->left);
		q.push_back(node);
		inorder(node->right);
	}
private:
	deque<TreeNode*> q;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end


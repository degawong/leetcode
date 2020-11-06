/*
 * @Author: your name
 * @Date: 2020-10-28 17:46:10
 * @LastEditTime: 2020-10-28 18:11:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\653.两数之和-iv-输入-bst.cpp
 */
/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        inorder(root);
        if(v.size() < 2) return false;
		for(int i = 0; i < v.size(); ++i) {
			if(s.count(k - v[i])) return true;
		}
		int left = 0;
		int right = v.size() - 1;
		while(left < right) {
			if(v[left] + v[right] < k) ++left;
			if(v[left] + v[right] > k) --right;
			if(v[left] + v[right] == k) return true;			
		}
		return false;
    }
private:
	void inorder(TreeNode * node) {
		if(node == nullptr) return;
		inorder(node->left);
		// s.insert(node->val);
		v.push_back(node->val);
		inorder(node->right);
	}
private:
	set<int> s;
	vector<int> v;
};
// @lc code=end


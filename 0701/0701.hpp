/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-11-12 09:40:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0701\0701.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
		if(root == nullptr) return new TreeNode(val);
		dfs(root, val);		
        return root;
    }
	void dfs(TreeNode* root, int val) {
		if(root->val > val) {
			if(root->left == nullptr) {
				root->left = new TreeNode(val);
			} else {
				dfs(root->left, val);
			}
		}
		if(root->val < val) {
			if(root->right == nullptr) {
				root->right = new TreeNode(val);
			} else {
				dfs(root->right, val);
			}
		}
	}
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-19 11:30:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0094\0094.hpp
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

// class Solution {
// 	// recursive
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ret;
// 		TreeNode * l = root;
// 		while(l)
// 		return ret;
//     }
// };

class Solution {
	// recursive
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
		inorder(root, ret);
		return ret;
    }
private:
	void inorder(TreeNode* root, vector<int>& v) {
		if(root == nullptr) return;
		inorder(root->left, v);
		v.push_back(root->val);
		inorder(root->right, v);
	}
};

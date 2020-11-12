/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-12 09:49:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0230\0230.hpp
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
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
		return v[k - 1]->val;
    }
private:
	void inorder(TreeNode* node, int k) {
		if(node == nullptr) return;
		inorder(node->left, k);
		v.push_back(node);
		if(v.size() == k) return;
		inorder(node->right, k);
	}
private:
	vector<TreeNode*> v;
};

// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         inorder(root);
// 		return v[k - 1]->val;
//     }
// private:
// 	void inorder(TreeNode* node) {
// 		if(node == nullptr) return;
// 		inorder(node->left);
// 		v.push_back(node);
// 		inorder(node->right);
// 	}
// private:
// 	vector<TreeNode*> v;	
// };
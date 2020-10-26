/*
 * @Author: your name
 * @Date: 2020-10-20 16:04:25
 * @LastEditTime: 2020-10-26 14:31:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0105\0105.hpp
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
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int index = 0;
		if(preorder.size() == 0) return nullptr;
		if(preorder.size() == 1) return new TreeNode(preorder[0]);
		for(int i = 0; i < inorder.size(); ++i) {
			if(inorder[i] == preorder[0]) {
				index = i;
			}
		}
		vector<int> left_in{ inorder.begin(), inorder.begin() + index};		
		vector<int> right_in{ inorder.begin() + index + 1, inorder.end() };
		vector<int> left_pre{ preorder.begin() + 1, preorder.begin() + index + 1};
		vector<int> right_pre{ preorder.begin() + index + 1, preorder.end() };
		auto node = new TreeNode(preorder[0]);
		node->left = buildTree(left_pre, left_in);
		node->right = buildTree(right_pre, right_in);
		return node;
    }
};

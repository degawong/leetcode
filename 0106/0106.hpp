/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-26 15:00:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0106\0106.hpp
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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int index = 0;
		if(inorder.size() == 0) return nullptr;
		if(inorder.size() == 1) return new TreeNode(postorder[postorder.size() - 1]);
		for(int i = 0; i < inorder.size(); ++i) {
			if(inorder[i] == postorder[postorder.size() - 1]) {
				index = i;
			}
		}
		vector<int> left_in{ inorder.begin(), inorder.begin() + index};		
		vector<int> right_in{ inorder.begin() + index + 1, inorder.end() };
		vector<int> left_post{ postorder.begin(), postorder.begin() + index};
		vector<int> right_post{ postorder.begin() + index, postorder.end() - 1};
		auto node = new TreeNode(postorder[postorder.size() - 1]);
		node->left = buildTree(left_in, left_post);
		node->right = buildTree(right_in, right_post);
		return node;
    }
};
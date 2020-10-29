/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-10-29 11:24:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0654\0654.hpp
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if(nums.size() == 0) return nullptr;
		int index = 0;
		int value = INT_MIN;
		for(int i = 0; i < nums.size(); ++i) {
			if(nums[i] > value) {
				index = i;
				value = nums[i];
			}
		}
		auto node = new TreeNode(nums[index]);
		auto left = vector<int>{ nums.begin(), nums.begin() + index };
		auto right = vector<int>{ nums.begin() + index + 1, nums.end() };
		node->left = constructMaximumBinaryTree(left);
		node->right = constructMaximumBinaryTree(right);
		return node;
    }
};
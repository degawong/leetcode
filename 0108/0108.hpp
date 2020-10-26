/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-26 15:15:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0108\0108.hpp
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		int val = 0;
        if(nums.size() == 0) return nullptr;
		if(nums.size() == 1) return new TreeNode(nums[0]);
		auto node = new TreeNode(nums[nums.size() / 2]);
		vector<int> left = { nums.begin(), nums.begin() + nums.size() / 2 };
		vector<int> right = { nums.begin() + nums.size() / 2 + 1, nums.end() };
		node->left = sortedArrayToBST(left);
		node->right = sortedArrayToBST(right);
		return node;
    }
};

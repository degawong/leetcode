/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:32
 * @LastEditTime: 2020-11-06 11:37:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\1008\1008.hpp
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		vector<int> left;
		vector<int> right;
		auto ret = (TreeNode*)nullptr;
        if(preorder.size() == 0) return ret;
		ret = new TreeNode(preorder[0]);
		auto l_anchor = left_anchor(preorder);
		auto r_anchor = right_anchor(preorder);
		if(l_anchor == -1 && r_anchor == -1) return ret;
		else if (l_anchor == 1 && r_anchor == -1) {
			left = vector<int>{preorder.begin() + 1, preorder.end()};
		}
		else if (l_anchor == 1 && r_anchor != -1) {
			left = vector<int>{preorder.begin() + 1, preorder.begin() + r_anchor};
			right = vector<int>{preorder.begin() + r_anchor, preorder.end()};
		}
		else if (l_anchor == -1 && r_anchor != -1) {
			right = vector<int>{preorder.begin() + 1, preorder.end()};
		}
		ret->left = bstFromPreorder(left);
		ret->right = bstFromPreorder(right);
		return ret;
    }
private:
	int left_anchor(vector<int> v) {
		if(v.size() == 1 || v[1] > v[0]) return -1;
		return 1;
	}
	int right_anchor(vector<int> v) {
		int ret = -1;
		if(v.size() == 1) return ret;
		for(int i = 1; i < v.size(); ++i) {
			if(v[i] > v[0]) {
				ret = i; break;
			}
		}
		return ret;
	}
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-10-28 10:49:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0606\0606.hpp
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
    string tree2str(TreeNode* t) {
		string ret;
		if(t == nullptr) return ret;
		ret += to_string(t->val);
		if((t->right != nullptr) && (t->left == nullptr)) {
			ret += "()";
		}
		ret += node2str(t->left);
		ret += node2str(t->right);
		return ret;
    }
private:
    string node2str(TreeNode* t) {
		string ret;
		if(t == nullptr) return ret;
		ret.push_back('(');
		ret += to_string(t->val);
		if(t->left == nullptr && t->right == nullptr) {			
		}
		else if(t->left == nullptr) {
			ret += "()";
			ret += node2str(t->right);
		} else if(t->right == nullptr) {
			ret += node2str(t->left);
		} else {
			ret += node2str(t->left);
			ret += node2str(t->right);
		}
		ret.push_back(')');
		return ret;
    }
};

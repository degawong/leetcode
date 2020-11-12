/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-12 09:56:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0297\0297.hpp
 */

#include <cmath>
#include <string>
#include <sstream>
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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		if(root == nullptr) return "#";
		return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }
	
	TreeNode* build_tree(stringstream& ss) {
		string temp;
		ss >> temp;
		if(temp == "#") return nullptr;
		auto node = new TreeNode(stoi(temp));
		node->left = build_tree(ss);
		node->right = build_tree(ss);
		return node;
	}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
		return build_tree(ss);
    }
};

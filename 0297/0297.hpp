/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-12 11:26:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0297\0297.hpp
 */

#include <cmath>
#include <queue>
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
 
// class Codec {
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
// 		if(root == nullptr) return "#";
// 		return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
//     }
	
// 	TreeNode* build_tree(stringstream& ss) {
// 		string temp;
// 		ss >> temp;
// 		if(temp == "#") return nullptr;
// 		auto node = new TreeNode(stoi(temp));
// 		node->left = build_tree(ss);
// 		node->right = build_tree(ss);
// 		return node;
// 	}

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         stringstream ss(data);
// 		   return build_tree(ss);
//     }
// };

class Codec {
public:
	// level traversal
    string serialize(TreeNode* root) {
		string ret;
		queue<TreeNode*> q;
		if(root == nullptr) return "#";
		q.push(root);
		ret += to_string(root->val);
		while(!q.empty()) {
			auto node = q.front();
			q.pop();
			if(node->left == nullptr) ret += " #";
			else {
				q.push(node->left);
				ret += " " + to_string(node->left->val);
			}
			if(node->right == nullptr) ret += " #";
			else {
				q.push(node->right);
				ret += " " + to_string(node->right->val);
			}
		}
		return ret;
    }

    TreeNode* deserialize(string data) {
		string temp;
		int index = 0;
		vector<string> vs;
		queue<TreeNode*> q;
		stringstream ss(data);
		// data can not be a non element string, because minimum size of data is the 1(# ==> nullptr)
		ss >> temp;
		while(!temp.empty()) {
			vs.push_back(temp);
			temp.clear();
			ss >> temp;
		}
		auto root = generate_node(vs[index++]);
		if(root == nullptr) return root;
		q.push(root);
		while(!q.empty()) {
			auto node = q.front();
			q.pop();
			node->left = generate_node(vs[index++]);
			if(node->left != nullptr) q.push(node->left);
			node->right = generate_node(vs[index++]);
			if(node->right != nullptr) q.push(node->right);
		}
		return root;
    }

    TreeNode* generate_node(const string& data) {
		if(data == "#") return nullptr;
        return new TreeNode(stoi(data));
    }
};
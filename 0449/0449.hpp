/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-11-11 14:16:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\003.cpp
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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";
        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    TreeNode* rebuildTree(stringstream &ss){
        string tmp;
        ss >> tmp;
        if(tmp == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(tmp));
        node->left = rebuildTree(ss);
        node->right = rebuildTree(ss);
        return node;
    }
    
    // Decodes your encoded data to tree.  
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return rebuildTree(ss);
    }
};

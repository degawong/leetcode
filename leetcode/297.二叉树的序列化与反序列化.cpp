/*
 * @Author: your name
 * @Date: 2020-10-27 11:13:15
 * @LastEditTime: 2020-11-12 09:57:17
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\297.二叉树的序列化与反序列化.cpp
 */
/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
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

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end


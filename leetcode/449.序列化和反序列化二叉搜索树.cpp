/*
 * @Author: your name
 * @Date: 2020-11-11 13:50:46
 * @LastEditTime: 2020-11-11 14:09:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\449.序列化和反序列化二叉搜索树.cpp
 */
/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end


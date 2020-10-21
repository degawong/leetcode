/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-21 14:17:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0257\0257.hpp
 */

#include <cmath>
#include <string>
#include <vector>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        construct_paths(root, "", paths);
        return paths;
    }
private:
    void construct_paths(TreeNode* root, string path, vector<string>& paths) {
        if (root != nullptr) {
            path += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr) {
                paths.push_back(path);
            } else {
                path += "->";
                construct_paths(root->left, path, paths);
                construct_paths(root->right, path, paths);
            }
        }
    }
};



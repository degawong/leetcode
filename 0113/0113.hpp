/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-26 16:07:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0113\0113.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
		return ret;
    }
private:
    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) return;
        path.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == root->val) {
            ret.emplace_back(path);
        }
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
        path.pop_back();
    }
private:
    unordered_map<TreeNode*, TreeNode*> parent;
    void getPath(TreeNode* node) {
        vector<int> tmp;
        while (node != nullptr) {
            tmp.emplace_back(node->val);
            node = parent[node];
        }
        reverse(tmp.begin(), tmp.end());
        ret.emplace_back(tmp);
    }
private:
    vector<int> path;		
    vector<vector<int>> ret;
};

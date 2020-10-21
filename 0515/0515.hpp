/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:29
 * @LastEditTime: 2020-10-21 15:21:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0515\0515.hpp
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

// DFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return ret;
        dfs(root, 0);
        return ret;
    }
private:
    vector<int> ret;
    void dfs(TreeNode* node, int level) {
        if(ret.size() == level) ret.push_back(INT_MIN);
        ret[level] = max(ret[level], node->val);
        if(node->left) dfs(node->left, level+1);
        if(node->right) dfs(node->right, level+1);
    }	
};

// BFS
// class Solution {
// public:
//     vector<int> largestValues(TreeNode* root) {
//         vector<int> ret;
//         if(root == nullptr) return ret;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()) {
//             int levelSize = q.size();
//             int levelMax = INT_MIN;
//             for(int i = 0; i < levelSize; i++) {
//                 TreeNode* curNode = q.front();
//                 q.pop();
//                 levelMax = max(curNode->val, levelMax);
//                 if(curNode->left) q.push(curNode->left);
//                 if(curNode->right) q.push(curNode->right);
//             }
//             ret.push_back(levelMax);
//         }
//         return ret;
//     }
// };

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-22 16:09:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0110\0110.hpp
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

// class Solution {
// 	// current node is balanced and left subtree and right tree is balanced
// public:
//     bool isBalanced(TreeNode* root) {
// 		if(root == nullptr) return true;
// 		return abs(__height(root->left) - __height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
//     }
// private:
//     int __height(TreeNode* node) {
// 		if(node == nullptr) return 0;
// 		return max(__height(node->left), __height(node->right)) + 1;
//     }
// };
class Solution {
	// seems like memory search
public:
    bool isBalanced(TreeNode* root) {
        return __height(root) >= 0;
    }
private:
    int __height(TreeNode* node) {
		if(node == nullptr) return 0;
        int leftHeight = __height(node->left);
        int rightHeight = __height(node->right);
        if (
			leftHeight == -1 ||
			rightHeight == -1 ||
			abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }
};

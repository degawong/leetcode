/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-11-05 17:11:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0114\0114.hpp
 */

#include <cmath>
#include <deque>
#include <stack>
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

class Solution {
public:
    void flatten(TreeNode* root) {
		deque<TreeNode*> dq;
		if(root == nullptr) return;
		auto node = root;
		dq.push_back(node);
		auto recorder = (TreeNode*)nullptr;
		while (!dq.empty()) {
			auto node = dq.back(); 
			dq.pop_back();
			if(recorder != nullptr) {
				recorder->left = nullptr;
				recorder->right = node;
			}
			if(node->right != nullptr) dq.push_back(node->right);
			if(node->left != nullptr) dq.push_back(node->left);
			recorder = node;
		}
	}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         root = build(root);
//     }

//     TreeNode*build(TreeNode*root)
//     {
        
//         if(!root||root->right==NULL&&root->left==NULL)//叶子节点，空节点直接返回
//             return root;
//         //先序遍历建立链表
//         root->left = build(root->left);
//         root->right = build(root->right);
//         //找到左子树的最右端;
//         TreeNode*p = root->left;
//         if(p)
//         {
//             while(p->right!=NULL)
//                 p=p->right;
//             p->right = root->right;
//             root->right = root->left;
//         }
//         root->left = NULL;
//         return root;
//     }
// };

// 作者：unicornss
// 链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/lao-nian-ren-di-gui-si-lu-by-unicornss/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if (root == nullptr) {
//             return;
//         }
//         auto stk = stack<TreeNode*>();
//         stk.push(root);
//         TreeNode *prev = nullptr;
//         while (!stk.empty()) {
//             TreeNode *curr = stk.top(); stk.pop();
//             if (prev != nullptr) {
//                 prev->left = nullptr;
//                 prev->right = curr;
//             }
//             TreeNode *left = curr->left, *right = curr->right;
//             if (right != nullptr) {
//                 stk.push(right);
//             }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
//             if (left != nullptr) {
//                 stk.push(left);
//             }
//             prev = curr;
//         }
//     }
// };

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
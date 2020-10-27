/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-27 10:13:30
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0173\0173.hpp
 */

#include <cmath>
#include <deque>
#include <queue>
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
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
  
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
		inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
		auto node = q.front();
		q.pop_front();
		return node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
		return !q.empty();
    }
private:
	void inorder(TreeNode* node) {
		if(node == nullptr) return;
		inorder(node->left);
		q.push_back(node);
		inorder(node->right);
	}
private:
	deque<TreeNode*> q;
};

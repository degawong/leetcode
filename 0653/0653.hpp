/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-10-28 18:25:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0653\0653.hpp
 */

#include <set>
#include <cmath>
#include <deque>
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
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        inorder(root);
        if(v.size() < 2) return false;
		// for(int i = 0; i < v.size(); ++i) {
		// 	if(s.count(k - v[i])) return true;
		// }
		int left = 0;
		int right = v.size() - 1;
		while(left < right) {
			if(v[left] + v[right] < k) {
				++left; continue;
			}
			if(v[left] + v[right] > k) {
				--right; continue;
			}
			if(v[left] + v[right] == k) return true;			
		}
		return false;
    }
private:
	void inorder(TreeNode * node) {
		if(node == nullptr) return;
		inorder(node->left);
		// s.insert(node->val);
		v.push_back(node->val);
		inorder(node->right);
	}
private:
	set<int> s;
	vector<int> v;
};

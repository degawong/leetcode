/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:29
 * @LastEditTime: 2020-11-10 17:39:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0589\0589.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        dfs(root);
		return ret;
    }
private:
	vector<int> ret;
	void dfs(Node* root) {
		if(root == nullptr) return;
		ret.push_back(root->val);
		for(auto n : root->children) {
			dfs(n);
		}
	}
};

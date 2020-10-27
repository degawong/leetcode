/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-27 09:26:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0117\0117.hpp
 */

#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
		deque<Node*> dq;
        if(root == nullptr) return nullptr;
		dq.push_back(root);
		while(!dq.empty()) {
			auto size = dq.size();
			for(int i = 0; i < size; ++i) {
				auto node = dq.front();
				dq.pop_front();
				if(i < size - 1) {
					node->next = dq.front();
				}
				if(node->left != nullptr) dq.push_back(node->left);
				if(node->right != nullptr) dq.push_back(node->right);
			}
		}
		return root;
    }
};

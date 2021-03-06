/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:28
 * @LastEditTime: 2020-11-11 13:42:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0429\0429.hpp
 */

#include <cmath>
#include <queue>
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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
		vector<vector<int>> ret;
		if(root == nullptr) return ret;
		q.push(root);
		while(!q.empty()) {
			vector<int> element;			
			auto size = q.size();
			for(auto i = 0; i < size; ++i) {
				auto node = q.front();
				q.pop();				
				for(auto r : node->children) {
					q.push(r);
				}
				element.push_back(node->val);
			}
			ret.push_back(element);
		}
		return ret;
    }
};

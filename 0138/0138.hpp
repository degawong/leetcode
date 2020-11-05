/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-11-05 15:01:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0138\0138.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {		
        if(head == nullptr) return nullptr;
		if(um.find(head) != um.end()) {
			return um[head];
		}
		auto node = new Node(head->val);
		um[head] = node;
		node->next = copyRandomList(head->next);
		node->random = copyRandomList(head->random);
		return node;
    }
private:
	unordered_map<Node*, Node*> um;
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-11-05 11:34:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0133\0133.hpp
 */

#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> um;
    Node* cloneGraph(Node* node) {
		// dfs
        if (node == nullptr) return node;
        if (um.find(node) != um.end()) {
            return um[node];
        }
        auto ret = new Node(node->val);
        um[node] = ret;
        for (auto& neighbor : node->neighbors) {
            ret->neighbors.emplace_back(cloneGraph(neighbor));
        }
        return ret;	
    }
    Node* cloneGraph(Node* node) {
		// bfs
        queue<Node*> q;		
        if (node == nullptr) return node;
        unordered_map<Node*, Node*> um;
        q.push(node);
        um[node] = new Node(node->val);
        while (!q.empty()) {
            auto n = q.front(); q.pop();            
            for (auto& neighbor : n->neighbors) {
                if (um.find(neighbor) == um.end()) {
                    um[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                um[n]->neighbors.emplace_back(um[neighbor]);
            }
        }
        return um[node];	
    }
};

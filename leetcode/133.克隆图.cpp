/*
 * @Author: your name
 * @Date: 2020-11-05 10:53:45
 * @LastEditTime: 2020-11-05 11:34:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\133.克隆图.cpp
 */
/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
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
*/

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
};
// @lc code=end


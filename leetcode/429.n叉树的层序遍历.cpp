/*
 * @Author: your name
 * @Date: 2020-11-11 13:34:26
 * @LastEditTime: 2020-11-11 13:42:25
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\429.n叉树的层序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
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
*/

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
// @lc code=end


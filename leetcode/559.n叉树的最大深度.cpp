/*
 * @Author: your name
 * @Date: 2020-11-10 17:28:08
 * @LastEditTime: 2020-11-10 17:31:57
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\559.n叉树的最大深度.cpp
 */
/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N叉树的最大深度
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
    int maxDepth(Node* root) {
        int ret = 0;
		if(root == nullptr) return 0;
		for(auto n : root->children){
			ret = max(ret, maxDepth(n));
		}
		return ret + 1;
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-11-10 17:39:56
 * @LastEditTime: 2020-11-11 10:32:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\590.n叉树的后序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
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
    vector<int> postorder(Node* root) {
        dfs(root);
		return ret;
    }
private:
	vector<int> ret;
	void dfs(Node* root) {
		if(root == nullptr) return;
		for(auto n : root->children) {
			dfs(n);
		}
		ret.push_back(root->val);	
	}
};
// @lc code=end


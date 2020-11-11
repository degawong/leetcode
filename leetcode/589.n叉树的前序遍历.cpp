/*
 * @Author: your name
 * @Date: 2020-11-10 17:35:05
 * @LastEditTime: 2020-11-10 17:39:15
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\589.n叉树的前序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
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
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-10-30 11:09:19
 * @LastEditTime: 2020-11-05 15:03:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\138.复制带随机指针的链表.cpp
 */
/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
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
// @lc code=end


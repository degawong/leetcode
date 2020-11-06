/*
 * @Author: your name
 * @Date: 2020-10-23 15:40:44
 * @LastEditTime: 2020-10-30 13:36:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\234.回文链表.cpp
 */
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        deque<ListNode*> dq;
		while(head != nullptr) {
			dq.push_back(head);
			head = head->next;
		}
		while(!dq.empty()) {
			auto l = dq.front(); dq.pop_front();
			if(!dq.empty()) {
				auto r = dq.back(); dq.pop_back();			
				if(l->val != r->val) return false;
			}
		} 
		return true;        
    }
};
// @lc code=end


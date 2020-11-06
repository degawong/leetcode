/*
 * @Author: your name
 * @Date: 2020-10-30 11:31:02
 * @LastEditTime: 2020-10-30 13:26:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\143.重排链表.cpp
 */
/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
		auto s = head;
		while(s != nullptr) {
			dq.push_back(s);
			s = s->next;
		}
		ListNode* recorder = nullptr;
		while(!dq.empty()) {
			auto l = dq.front(); dq.pop_front();
			if(recorder != nullptr) recorder->next = l;
			if(!dq.empty()) {
				auto r = dq.back(); dq.pop_back();			
				l->next = r;
				r->next = nullptr;
				recorder = r;
			} else {
				l->next = nullptr;
			}
		}
    }
};
// @lc code=end


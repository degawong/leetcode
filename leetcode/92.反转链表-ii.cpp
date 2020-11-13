/*
 * @Author: your name
 * @Date: 2020-10-30 10:36:42
 * @LastEditTime: 2020-11-13 15:35:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\92.反转链表-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		auto size = n - m;
        if(head == nullptr || size == 0) return head;
		auto dummy = new ListNode(0);
		dummy->next = head;
		auto anchor = dummy;
		while(--m > 0) {
			anchor = anchor->next;
		}
		anchor->next = reverse_by_count(anchor->next, size);
		return dummy->next;
    }
private:
	ListNode* reverse_by_count(ListNode* head, int size) {
		auto dummy = new ListNode(0);
		dummy->next = head;
		auto op = head;
		auto tail = head;
		auto recorder = (ListNode*)nullptr;
		for(int i = 0; i < size; ++i) {
			auto next = op->next;
			op->next = recorder;
			recorder = op;
			op = next;
		}
		tail->next = op->next;
		op->next = recorder;
		return op;
	}	
};
// @lc code=end


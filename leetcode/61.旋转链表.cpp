/*
 * @Author: your name
 * @Date: 2020-10-30 10:09:07
 * @LastEditTime: 2020-10-30 10:35:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\61.旋转链表.cpp
 */
/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        auto slow = head;
        auto anchor = head;
        auto assist = head;
        auto count = 0;
		if(head == nullptr) return nullptr;
        while(assist != nullptr) {
            count += 1;
            assist = assist->next;
        }
        k = k % count;        
		while(k-- > 0) {
			if(anchor->next == nullptr) anchor = head;
			else anchor = anchor->next;
		}
		if(anchor == head) return head;
		while(anchor->next != nullptr) {
			slow = slow->next;
            anchor = anchor->next;
		}
		anchor->next = head;        
		auto ret = slow->next;
        slow->next = nullptr;
		return ret;        
    }
};
// @lc code=end


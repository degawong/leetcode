/*
 * @Author: your name
 * @Date: 2020-10-19 15:12:23
 * @LastEditTime: 2020-11-13 15:30:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0092\0092.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
 
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

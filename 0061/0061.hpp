/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-30 10:18:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0061\0061.hpp
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
    ListNode* rotateRight(ListNode* head, int k) {
		auto anchor = head;
		if(head == nullptr) return nullptr;
		while(k-- > 0) {
			if(anchor->next == nullptr) anchor = head;
			else anchor = anchor->next;
		}
		auto ret = anchor;
		if(anchor == head) return head;
		while(anchor->next != nullptr) {
			anchor = anchor->next;
		}
		anchor->next = head;
		while(head->next != ret) {
			head = head->next;
		}
		head->next = nullptr;
		return ret;
    }
};
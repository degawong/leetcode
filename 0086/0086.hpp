/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-16 14:25:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0086\0086.hpp
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
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto left = new ListNode(0);
		auto right = new ListNode(0);
		auto dummy_left = left;
		auto dummy_right = right;
		while(head != nullptr) {
			if(head->val < x) {
				dummy_left->next = head;
				dummy_left = dummy_left->next;
			} else {
				dummy_right->next = head;
				dummy_right = dummy_right->next;
			}
			head = head->next;
		}
		dummy_right->next = nullptr;
		dummy_left->next = right->next;
		auto ret = left->next;
		delete left;
		delete right;
		return ret;
    }
};

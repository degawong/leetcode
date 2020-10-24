/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:28
 * @LastEditTime: 2020-10-16 16:44:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0328\0328.hpp
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
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
		if(head == nullptr) return nullptr;
        auto odd = head;
		auto even = head->next;
		auto dummy_odd = odd;
		auto dummy_even = even;
		while(dummy_even != nullptr && dummy_even->next != nullptr) {
			dummy_odd->next = dummy_even->next;
			dummy_odd = dummy_odd->next;
			if(dummy_odd != nullptr) {
				dummy_even->next = dummy_odd->next;
			}
			dummy_even = dummy_even->next;
		}
		dummy_odd->next = even;
		return odd;
    }
};

/*
 * @Author: your name
 * @Date: 2020-10-19 15:11:28
 * @LastEditTime: 2020-10-21 18:47:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0002\0002.hpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(0);
		auto ret = dummy;
		int carry_bit = 0;
		while(l1 != nullptr || l2 != nullptr) {
			if(l1 == nullptr) {
				if(carry_bit == 1 && l2->val == 9) {
					l2->val = 0;
					carry_bit = 1;
				} else {
					l2->val += carry_bit;
					carry_bit = 0;
				}
				ret->next = l2;
				l2 = l2->next;				
			} else if(l2 == nullptr) {
				if(carry_bit == 1 && l1->val == 9) {
					l1->val = 0;
					carry_bit = 1;
				} else {
					l1->val += carry_bit;
					carry_bit = 0;
				}
				ret->next = l1;
				l1 = l1->next;		
			} else {
				auto temp = (l1->val + l2->val + carry_bit);
				l1->val = temp % 10;
				carry_bit = (temp >= 10) ? 1 : 0;
				ret->next = l1;
				l1 = l1->next;
				l2 = l2->next;
			}
			ret = ret->next;
		}
		if(carry_bit == 1) ret->next = new ListNode(1);
		return dummy->next;
    }
};

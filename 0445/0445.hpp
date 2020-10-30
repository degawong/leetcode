/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:29
 * @LastEditTime: 2020-10-30 14:30:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0445\0445.hpp
 */

#include <cmath>
#include <deque>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* ret = nullptr;
		vector<ListNode*> v_1;
		vector<ListNode*> v_2;
		if(l1 == nullptr && l2 == nullptr) return nullptr; 
		while(l1 != nullptr || l2 != nullptr) {
			if(l1 != nullptr) {
				v_1.push_back(l1);
				l1 = l1->next;
			}
			if(l2 != nullptr) {
				v_2.push_back(l2);
				l2 = l2->next;
			}	
		}
		int s1 = v_1.size();
		int s2 = v_2.size();
		for(int i = 0; i < max(v_1.size(), v_2.size()); ++i) {
			int res = 0;
			if((i < v_1.size()) && (i < v_2.size())) {
				auto temp = v_1[s1 - 1 - i]->val + v_2[s2 - 1 - i]->val + carry;
				res = (temp) % 10;
				carry = (temp) / 10;
			} else if(i >= v_1.size()) {
				auto temp = v_2[s2 - 1 - i]->val + carry;
				res = (temp) % 10;				
				carry = (temp) / 10;				
			} else if(i >= v_2.size()) {
				auto temp = v_1[s1 - 1 - i]->val + carry;
				res = (temp) % 10;			
				carry = (temp) / 10;				
			}
			auto node = new ListNode(res);
			node->next = ret;
			ret = node;
		}
		if(carry == 1) {
			auto node = new ListNode(1);
			node->next = ret;
			ret = node;
		}
		return ret;
    }
};

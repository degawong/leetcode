/*
 * @Author: your name
 * @Date: 2020-10-19 15:12:54
 * @LastEditTime: 2020-10-30 13:25:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0143\0143.hpp
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
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
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

/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-30 13:36:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\003.cpp
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
    bool isPalindrome(ListNode* head) {
        deque<ListNode*> dq;
		while(head != nullptr) {
			dq.push_back(head);
			head = head->next;
		}
		while(!dq.empty()) {
			auto l = dq.front(); dq.pop_front();
			if(!dq.empty()) {
				auto r = dq.back(); dq.pop_back();			
				if(l->val != r->val) return false;
			}
		} 
		return true;      
    }
};

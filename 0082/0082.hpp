/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-16 10:32:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0082\0082.hpp
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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(0);
		dummy->next = head;
		auto temp = dummy;
		while(temp->next != nullptr) {
			auto back = temp->next;
			auto front = temp->next;
			while(front != nullptr && front->val == back->val) {
				front = front->next;
			}
			if(back->next != front) temp->next = front;
			else temp = temp->next;
		}
		auto ret = dummy->next;
		delete dummy;
		return ret;
    }
};

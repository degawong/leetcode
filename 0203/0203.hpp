/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-15 09:18:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0203\0203.hpp
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
    ListNode* removeElements(ListNode* head, int val) {
		auto dummy = new ListNode(0);
		dummy->next = head;
		auto temp = dummy;
		while(temp->next != nullptr) {
			if(val == temp->next->val) {
				temp->next = temp->next->next;
			} else {
				temp = temp->next;
			}
		}
		auto ret = dummy->next;
		delete dummy;
		return ret;
    }
};

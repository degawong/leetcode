/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-16 15:17:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\003.cpp
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
    ListNode *detectCycle(ListNode *head) {
		auto fast = head;
		auto slow = head;
		while(fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if(fast == slow) {
				slow = head;
				while(slow != fast) {
					fast = fast->next;
					slow = slow->next;					
				}
				return slow;
			}
		}
		return nullptr;
    }
};

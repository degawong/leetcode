/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:25
 * @LastEditTime: 2020-10-14 18:44:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0024\0024.hpp
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
    ListNode* swapPairs(ListNode* head) {
		auto dummy = new ListNode{0};
		dummy->next = head;
		auto temp = dummy;
		while((temp->next != nullptr) && (temp->next->next != nullptr)) {
			auto left = temp->next;
			auto right = temp->next->next;
			left->next = right->next;
			right->next = left;
			temp->next = right;
			temp = left;
		}
		auto ret = dummy->next;
		delete dummy;
		return ret;
    }
};

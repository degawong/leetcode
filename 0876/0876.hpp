/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:31
 * @LastEditTime: 2020-10-15 11:09:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0876\0876.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// leetcode : https://leetcode-cn.com/problems/middle-of-the-linked-list/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
		auto fast = head;
		auto slow = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
    }
};

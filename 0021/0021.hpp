/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:25
 * @LastEditTime: 2020-10-15 09:54:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0021\0021.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// leetcode : https://leetcode-cn.com/problems/merge-two-sorted-lists/

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* ret = nullptr;
		if(l1 == nullptr) return l2;
		if(l2 == nullptr) return l1;
        if (l1->val <= l2->val) {
			ret = l1;
			ret->next = mergeTwoLists(l1->next, l2);
		} else {
			ret = l2;
			ret->next = mergeTwoLists(l1, l2->next);
		}
		return ret;
    }
};
// reference
// https://blog.csdn.net/xiangxianghehe/article/details/81739181
/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-14 15:34:52
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

// NOTE: û���ͷ��ڴ�������ڴ����

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

//���ߣ�TeFuirnever
//���ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/solution/shou-hui-man-hua-tu-jie-leetcodezhi-shan-chu-pai-2/

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		auto cur = head;
		while (cur&&cur->next) {
			if (cur->next->val == cur->val) {
				cur->next = cur->next->next;
			}
			else {
				cur = cur->next;
			}
		}
		return head;
	}
};

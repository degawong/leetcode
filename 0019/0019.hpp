/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:25
 * @LastEditTime: 2020-10-14 17:11:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0019\0019.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		auto fast = dummy;
		auto slow = dummy;
		for (int i = 0; i < n; ++i) {
			fast = fast->next;
		}
		while (fast->next != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		auto ret = dummy->next;
		delete dummy;
		return ret;
	}
};

//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* dummy = new ListNode(0);  //哑节点
//        if(!head)  return head;
//        dummy->next = head;
//        ListNode* p = dummy;
//        ListNode* q = dummy;
//        for(int i=0; i<n;i++)
//        {
//        q=q->next;
//        }
//        while(q->next)
//        {
//           p= p->next;
//           q= q->next;
//        }
//        p->next = p->next->next;  //删除p->next的节点
//   
//        ListNode* res = dummy->next;
//        delete dummy;   //删除哑节点
//        return res;
//
//    }
//};

// 链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/cgao-xiao-jie-fa-shan-chu-di-nge-jie-dian-by-tarax/
/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-14 15:35:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\003.cpp
 */
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

//����: 1->2->3->4->5->NULL
//���: 5->4->3->2->1->NULL
// https://leetcode-cn.com/problems/reverse-linked-list/

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* temp;
		ListNode* pre = nullptr;
		ListNode* inverse = nullptr;
		while (head != nullptr) {
			inverse = head;
			head = head->next;
			inverse->next = pre;
			pre = inverse;
		}
		return inverse;
    }
};

//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//        ListNode* pre,*phead,*temp;
//        phead = head;  //��pheadָ������ͷ�����α�ʹ��
//	    pre = NULL;  //preΪphead��ǰһ�����
//        while(phead != NULL){
//            temp = pre;
//		    pre = phead;
//		    phead = phead->next;
//
//            pre->next = temp;  //pre�ӵ�֮ǰ�Ľڵ� 
//        }
//        return pre;
//    }
////���ߣ�ben-ben-xiao-sheng
////���ӣ�https://leetcode-cn.com/problems/reverse-linked-list/solution/san-jie-dian-fa-fan-zhuan-xiang-jie-by-ben-ben-xia/
//};

/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-14 15:35:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\003.cpp
 */
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

//https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
//���дһ��������ʹ�����ɾ��ĳ�������и����ģ���ĩβ���ڵ㡣���뺯����Ψһ����ΪҪ��ɾ���Ľڵ� 
//�������ٰ��������ڵ㡣
//���������нڵ��ֵ����Ψһ�ġ�
//�����Ľڵ�Ϊ��ĩβ�ڵ㲢��һ���������е�һ����Ч�ڵ㡣
//��Ҫ����ĺ����з����κν����

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    void deleteNode(ListNode* node) {
//        node->val = node->next->val;
//        node->next = node->next->next;
//    }
//};
//https://blog.csdn.net/xiangxianghehe/article/details/81739181

class Solution {
public:
    void deleteNode(ListNode* node) {
		while (node->next->next != nullptr) {
			node->val = node->next->val;
			node = node->next;
		}
		node->val = node->next->val;
		node->next = nullptr;
    }
};

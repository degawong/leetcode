/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-30 09:36:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0109\0109.hpp
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
 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
		auto ret = build_balanced_tree(head, nullptr);
		return build_balanced_tree(head, nullptr);
    }
private:
	TreeNode* build_balanced_tree(ListNode* head, ListNode* tail) {
		auto fast = head;
		auto slow = head;
		if(head == tail || head == nullptr) return nullptr;
		while(fast != tail && fast->next != tail) {
			slow = slow->next;
			fast = fast->next->next;
		}
		auto ret = new TreeNode(slow->val);
		ret->left = build_balanced_tree(head, slow);
		ret->right = build_balanced_tree(slow->next, tail);
		return ret;
	}
};

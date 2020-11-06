/*
 * @Author: your name
 * @Date: 2020-10-30 14:58:58
 * @LastEditTime: 2020-10-30 15:29:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\725.分隔链表.cpp
 */
/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
		auto head = root;
		vector<ListNode*> ret;
		vector<ListNode*> element;
		while(head != nullptr) {
			element.push_back(head);
			head = head->next;
		}
		if(k > element.size()) {
			head = root;
			for(int i = 0; i < k; ++i) {
				auto ele = (i < element.size() ? element[i] : nullptr);
                if(ele != nullptr) ele->next = nullptr;
				ret.push_back(ele);
			}
			return ret;
		}
		auto seg = element.size() / k;
		int carry = element.size() % k;
		head = root;
		auto size = 0;
		for(int i = 0; i < k; ++i) {
			size += (i == 0 ? seg + carry : seg);
			element[size - 1]->next = nullptr;
			ret.push_back(head);
			head = element[min(size, int(element.size() - 1))];
		}
		return ret;	
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-10-30 09:01:46
 * @LastEditTime: 2020-10-30 09:36:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\109.有序链表转换二叉搜索树.cpp
 */
/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
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
// @lc code=end


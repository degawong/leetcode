/*
 * @Author: your name
 * @Date: 2020-09-30 14:48:53
 * @LastEditTime: 2020-10-20 11:32:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\main.cpp
 */

#include <vector>
#include <iostream>

#include <0198.hpp>

using namespace std;

// void pre_order(TreeNode *root)
// {
// 	if (root == nullptr)
// 		return;
// 	cout << root->val << " ";
// 	pre_order(root->left);
// 	pre_order(root->right);
// }

int main(int argc, const char *argv[])
{

	Solution s;

	// listnode
	// ListNode _1(1);
	// ListNode _2(4);
	// ListNode _3(3);
	// ListNode _4(2);
	// ListNode _5(5);
	// ListNode _6(2);
	// _1.next = &_2;
	// _2.next = &_3;
	// _3.next = &_4;
	// _4.next = &_5;

	// treenode
	// TreeNode _1(1);
	// TreeNode _2(2);
	// TreeNode _3(3);
	// TreeNode _4(4);
	// TreeNode _7(5);
	// _1.left = &_2;
	// _1.right = &_3;
	// _2.left = &_4;
	// _3.right = &_7;

	// vector<int> inorder{9, 3, 15, 20, 7};
	// vector<int> preorder{3, 9, 20, 15, 7};

	// pre_order(s.buildTree(preorder, inorder));

	vector<int> v{2, 7, 9, 3, 1};
	cout << s.rob(v) << endl;

	return 0;
}

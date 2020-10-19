/*
 * @Author: your name
 * @Date: 2020-09-30 14:48:53
 * @LastEditTime: 2020-10-19 16:55:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\main.cpp
 */

#include <iostream>

#include <0103.hpp>

using namespace std;

int main(int argc, const char* argv[]){
	
	Solution s;

	vector<int> nums { 21, 21 };
	
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
	TreeNode _1(1);
	TreeNode _2(2);
	TreeNode _3(3);
	TreeNode _4(4);
	TreeNode _7(5);
	_1.left = &_2;
	_1.right = &_3;
	_2.left = &_4;
	_3.right = &_7;

	auto res = s.zigzagLevelOrder(&_1);

	for(auto outer : res) {
		for(auto inner : outer) {
			cout << inner << " ";
		}
		cout <<endl;
	}

    return 0;
}

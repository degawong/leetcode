/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-14 15:33:18
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

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.size() == 0) return 0;
		int size = 0;
		int i = s.size() - 1;
		for (; i >= 0; --i) {
			if (s[i] != ' ') break;
		}
		for (; i >= 0; --i) {
			if (s[i] == ' ') return size;
			size = size + 1;
		}
		return size;
	}
};

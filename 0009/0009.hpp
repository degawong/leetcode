/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-14 15:30:44
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
    bool isPalindrome(int x) {
		if (0 > x) {
			return false;
		}
		else {
			int inf[20];
			int _ = x;

			int length = 0;
			for (int i = 0; _ > 0; ++i) {
				inf[i] = _ % 10;
				_ /= 10;
				length += 1;
			}
			for (int i = 0; i < length / 2; ++i) {
				if (inf[i] != inf[length - 1 - i]) {
					return false;
				}
			}
			return true;
		}
    }
};

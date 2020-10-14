/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-14 15:34:05
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
	int mySqrt(int x) {
		if (x == 0) return 0;
		if (x == 1) return 1;
		if (x == 2) return 1;
		int l = 0;
		int r = x;
		int mid = (l + r) / 2;
		while (l <= r) {
			if (x / mid > mid) {
				if (l == mid) return mid;
				l = mid;
				mid = (l + r) / 2;
			}
			else if (x / mid < mid) {
				if (r == mid) return mid;
				r = mid;
				mid = (l + r) / 2;
			}
			else {
				return mid;
			}
		}
		return mid + 1;
	}
};

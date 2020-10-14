/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-14 15:34:22
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
	int climbStairs(int n) {
		return __climb_step(n);
	}
private:
	int __climb(int n) {
		if(n < 1) return 0;
		if(n == 1) return 1;
		if (n == 2) return 2;
		if (__recorder[n] == -1) {
			__recorder[n] = __climb(n - 1) + __climb(n - 2);
		}
		return __recorder[n];
	}
	int __climb_step(int n) {
		if(n == 1) return 1;
		if (n == 2) return 2;
		__recorder.resize(n + 1, -1);
		__recorder[0] = 0;
		__recorder[1] = 1;
		__recorder[2] = 2;
		return __climb(n - 1) + __climb(n - 2);
	}
private:
	vector<int> __recorder;
};

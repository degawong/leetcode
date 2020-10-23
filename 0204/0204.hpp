/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-23 13:58:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0204\0204.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
	// Eratosthenes
public:
    int countPrimes(int n) {
		int ret = 0;
		vector<bool> signs(n, true);
		for (int i = 2; i < n; ++i) {
			if (signs[i]) {
				ret += 1;
				for (int j = i + i; j < n; j += i) {
					signs[j] = false;
				}
			}
		}
    	return ret;
    }
};

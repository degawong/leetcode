/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:31
 * @LastEditTime: 2020-10-30 16:23:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0908\0908.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
		int _max = INT_MIN;
		int _min = INT_MAX;
		for(auto r : A) {
			if(_max < r) _max = r;
			if(_min > r) _min = r;
		}
		return max(0, _max - _min - 2 * K);
    }
};

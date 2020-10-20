/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-20 11:30:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0198\0198.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	int rob(vector<int> &nums) {
		int a = 0;
		int b = 0;
		for(auto ref : nums) {
			auto temp = a;
			a = max(a, b);
			b = ref + temp;
		}
		return max(a, b);
	}
};

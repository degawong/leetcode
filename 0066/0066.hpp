/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-14 15:33:43
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
private:
	inline int get_extra(bool cond) {
		if (cond) {
			return 1;
		}
		else {
			return 0;
		}
	}
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0) return vector<int> { };
		auto add = 0;
		vector<int> ret(digits.size());
		ret[digits.size() - 1] = (digits[digits.size() - 1] + 1) % 10;
		add = get_extra(digits[digits.size() - 1] == 9);
		for (int i = digits.size() - 2; i >= 0; --i) {
			ret[i] = (digits[i] + add) % 10;
			add = get_extra(ret[i] == 0 && digits[i] == 9);
		}
		if (add == 1) {
			ret.insert(ret.begin(), 1);
		}
		return ret;
	}
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-06 15:45:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0238\0238.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int size = nums.size();
		vector<int> ret(size, 0);
		vector<int> lm(size, nums[0]);
		vector<int> rm(size, nums[size - 1]);
		for(int i = 1; i < size; ++i) {
			lm[i] = lm[i - 1] * nums[i];
			rm[size - i - 1] = rm[size - i] * nums[size - i - 1];
		}
		for(int i = 1; i < size - 1; ++i) ret[i] = lm[i - 1] * rm[i + 1];
		ret[0] = rm[1];
		ret[size - 1] = lm[size - 1 - 1];
		return ret;
    }
};

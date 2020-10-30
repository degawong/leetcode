/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:25
 * @LastEditTime: 2020-10-30 16:53:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0011\0011.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		auto left = 0;
		auto ret = INT_MIN;
		auto right = height.size() - 1;
		while(left < right) {
			ret = max(ret, (int)(right - left) * min(height[left], height[right]));
			if(height[left] < height[right]) ++left;
			else --right;
		}
		return ret;
    }
};

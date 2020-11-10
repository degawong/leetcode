/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-10 13:52:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0228\0228.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		auto left = 0;
		auto right = 1;
		vector<string> ret;
		if(nums.size() == 0) return ret;
		if(nums.size() == 1) return ret.push_back(to_string(nums[0])), ret;
		while(right < nums.size()) {
			if(nums[right] - nums[left] != (right - left)) {
				if(right - left == 1) {
					ret.push_back(to_string(nums[left]));				
				}
				else {
					ret.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
				}
				left = right;
			}
			right += 1;
		}
		if(right - left == 1) {
			ret.push_back(to_string(nums[left]));				
		}
		else {
			ret.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
		}
		return ret;
    }
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:25
 * @LastEditTime: 2020-10-15 17:12:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0001\0001.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		for(int i = 0; i < nums.size(); ++i) {
			auto _2 = equal(nums, i + 1, target - nums[i]);
			if(_2 != -1) {
				ret.push_back(i);
				ret.push_back(_2);
				break;
			}
		}
		return ret;
    }
private:
	int equal(vector<int>& nums, int start, int target) {
		for(int i = start; i < nums.size(); ++i) {
			if(nums[i] == target) {
				return i;
			}
		}
		return -1;
	}
};

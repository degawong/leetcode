/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:25
 * @LastEditTime: 2020-10-30 17:32:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0016\0016.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		auto ret = INT_MAX;
		auto diff = INT_MAX;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size() - 2; ++i) {
			auto left = i + 1;
			auto right = nums.size() - 1;
            while(left < right) {
                auto temp = nums[i] + nums[left] + nums[right];
                if(temp < target) ++left;
                if(temp > target) --right;
                if(temp == target) return target;
                if(diff > abs(target - temp)) ret = temp, diff = abs(target - temp);
            }
		}
		return ret;
    }
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-16 11:30:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0080\0080.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if(nums.size() ==0) return 0;
		auto back = 0;
		auto front = 0;
		while(front < nums.size()) {
			auto i = front;
			auto j = front;
			while((j < nums.size()) && (nums[i] == nums[j])) ++j;
			for(int k = 0; k < min(2, j - i); ++k) {
				nums[back++] = nums[j - 1];
			}
			front = j;
		}
		nums.erase(nums.begin() + back, nums.end());
		return nums.size();
    }
};

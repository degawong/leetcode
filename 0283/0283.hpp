/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-23 22:16:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0283\0283.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		auto fast = 0;
		auto slow = 0;
		if(nums.size() == 0) return;
    	while(fast < nums.size()) {
			if(nums[fast] == 0) {
				while(++fast < nums.size() && nums[fast] == 0);
				if(fast == nums.size()) break;
				nums[slow++] = nums[fast++];
			} else {
				nums[slow++] = nums[fast++];
			}
		}
		for(int i = slow; i < nums.size(); ++i) {
			nums[i] = 0;
		}
	}
};
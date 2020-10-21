/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:25
 * @LastEditTime: 2020-10-21 16:26:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0026\0026.hpp
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
		if(nums.size() == 0) return 0;
		int fast = 1;
		int slow = 0;
		while(fast < nums.size()) {
			if(nums[slow] == nums[fast]) {
				++fast;
			} else {
				nums[slow++ + 1] = nums[fast++];
			}
		}
		return slow + 1;
    }
};

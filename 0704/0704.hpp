/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-11-09 17:35:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0704\0704.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int mid = 0;
		int left = 0;
		int right = nums.size() - 1;				
		while(left <= right) {
			mid = left + (right - left) / 2;
			if(nums[mid] == target) return mid;
			if(nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
    }
};

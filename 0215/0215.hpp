/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-05 15:42:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0215\0215.hpp
 */

#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), std::greater_equal<int>());
		return nums[k - 1];
    }
};

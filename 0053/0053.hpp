/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-22 09:36:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0053\0053.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		if(nums.size() == 0) return 0;
		auto temp = 0;
		auto ret = nums[0];
		for(auto n : nums) {
			temp = max(temp + n, n);
			ret = max(ret, temp);
		}
		return ret;
		// initial version of memory search
		// if(nums.size() == 0) return 0;
		// vector<int> dp(nums.size(), 0);
		// dp[0] = nums[0];
		// for(int i = 1; i < nums.size(); ++i) {
		// 	dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		// }
		// auto ret = 0;
		// for(auto m : dp) {
		// 	if(ret < m) ret = m;
		// }
		// return ret;		
    }
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-05 17:20:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0198\0198.hpp
 */

#include <cmath>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// dp[i] = max(dp[i-2] + nums[i], dp[i-1])

class Solution
{
public:
	// int rob(vector<int> &nums) {
	// 	int a = 0;
	// 	int b = 0;
	// 	for(auto ref : nums) {
	// 		auto temp = a;
	// 		a = max(a, b);
	// 		b = ref + temp;
	// 	}
	// 	return max(a, b);
	// }
	int rob(vector<int> &nums) {
		int ret = INT_MIN;
		if(nums.size() == 0) return 0;
		vector<int> dp(nums.size(), 0);
		if(nums.size() == 1) return nums[0];
		if(nums.size() == 2) return max(nums[0], nums[1]);
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for(int i = 2; i < nums.size(); ++i) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		for(auto m : dp) {
			if(ret < m) ret = m;
		}
		return ret;
	}
};

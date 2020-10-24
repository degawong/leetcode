/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:29
 * @LastEditTime: 2020-10-21 14:58:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0509\0509.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int fib(int N) {
		if(N == 0) return 0;
		if(N == 1) return 1;
		vector<int> dp(N + 1);
		dp[0] = 0;
		dp[1] = 1;
		for(int i = 2; i < N + 1; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[N];
    }
};

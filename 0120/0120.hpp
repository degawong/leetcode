/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-20 16:02:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0120\0120.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {	
		int ret = INT_MAX;
		if(triangle.size() == 0) return 0;
		for(int i = 1; i < triangle.size(); ++i) {
			for(int j = 0; j < triangle[i].size(); ++j) {
				triangle[i][j] += min(triangle[i - 1][min(max(0, j), int(triangle[i - 1].size() - 1))], triangle[i - 1][min(max(0, j - 1), int(triangle[i - 1].size() - 1))]);
			}
		}
		for(int i = 0; i < triangle[triangle.size() - 1].size(); ++i) {
			ret = min(ret, triangle[triangle.size() - 1][i]);
		}
		return ret;
    }
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-22 17:01:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0118\0118.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for(int i = 0; i < numRows; i++) {
			ret.push_back(vector<int>(i + 1, 1));
		}
       	for(int i = 0; i < numRows; i++) {
			for(int j = 1; j < i; ++j) {
				ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
			}
		}
       	return ret;
    }
};

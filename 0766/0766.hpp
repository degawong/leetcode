/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-10-30 16:03:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0766\0766.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		auto o_size = matrix.size();
        auto i_size = matrix[0].size();
		for(int i = 0 ; i < o_size; ++i) {
			auto anchor = matrix[i][0];
			for(int j = i + 1, k = 1; j < o_size && k < i_size; ++j, ++k) {
				if(matrix[j][k] != anchor) return false;
			}
		}
		for(int i = 0 ; i < i_size; ++i) {
			auto anchor = matrix[0][i];
			for(int j = 1, k = i + 1; j < o_size && k < i_size; ++j, ++k) {
				if(matrix[j][k] != anchor) return false;
			}
		}
		return true;
    }
};

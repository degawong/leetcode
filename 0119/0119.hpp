/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-11-10 10:52:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0119\0119.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> ret(rowIndex + 1, 1);
        if(rowIndex == 0) return vector<int>(1, 1);
        if(rowIndex == 1) return vector<int>(2, 1);
		for(int i = 2; i <= rowIndex; ++i) {
			for(int j = i - 1; j > 0; --j) {
				ret[j] += ret[j - 1];
			}
		}
       	return ret;
    }
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-11-06 14:06:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0171\0171.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
		int ret = 0;	
        for(int i = 0; i < s.size(); ++i) {
			ret = 26 * ret + (s[i] - 'A' + 1);
		}
		return ret;
    }
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-23 10:54:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0168\0168.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
		string ret;
		while(n > 0) {
			if(n % 26 == 0) ret.push_back('Z');
			else ret.push_back(n % 26 - 1 + 'A');
			n = floor((n - 1) / 26);
		}
		reverse(ret.begin(), ret.end());
		return ret;
    }
};

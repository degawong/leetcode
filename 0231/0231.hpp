/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-23 15:35:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0231\0231.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
		if(n == 1) return true;
		if(n == 0 || n % 2 != 0) return false;
		return isPowerOfTwo(n / 2);
    }
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:25
 * @LastEditTime: 2020-10-15 16:46:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0007\0007.hpp
 */

#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x / 10 == 0) return x;
        int ret = 0;
        while(x != 0) {
			// if the ret is INT_MIN or INT_MAX, the value x % 10 should small than 2
			// so it works well
            if(ret > INT_MAX / 10 || ret < INT_MIN / 10)
                return 0;
            ret = 10 * ret + x % 10;
            x /= 10;
        }
        return ret;
    }
};



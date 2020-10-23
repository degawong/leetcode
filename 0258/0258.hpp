/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-23 15:59:00
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0258\0258.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int ret = 0;
        if(num < 10) return num;
        while(num > 0) {
            ret += num % 10;
            num = num / 10;
        }
        return addDigits(ret);
    }
};

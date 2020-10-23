/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-23 16:27:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\003.cpp
 */
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto sum = 0;
        auto size = nums.size();
        for(auto n : nums) {
            sum += n;
        }
        return size * (size + 1) / 2 - sum;
    }
};

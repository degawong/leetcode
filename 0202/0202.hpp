/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-09 15:15:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0202\0202.hpp
 */

#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
		set<int> s;
		auto sum = 0;
		auto temp = 0;
		if(n == 1) return true;
		if(n == 0) return false;
		while(1) {
			sum = 0;
			while(n > 0) {
				temp = (n % 10);
				sum += (temp * temp);
				n = n / 10;
			}
			n = sum;
			if(sum == 1) return true;
			if(!s.insert(sum).second) return false;
		}
		return true;
    }
};

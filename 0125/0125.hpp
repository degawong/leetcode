/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-22 18:07:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0125\0125.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		if(s.size() == 0) return true;
		int left = 0;
		int right = s.size() - 1;
		while(left < right) {
			if(!__is_word(s[left])) {
				++left;
				continue;
			}
			if(!__is_word(s[right])) {
				--right;
				continue;
			}
			if(!__is_equal(s[left], s[right])) return false;
			left += 1;
			right -= 1;
		}
		return true;
    }
private:
	bool __is_word(const char c) {
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
	}
	bool __is_equal(const char _left, const char _right) {
		if(_left >= '0' && _left <= '9') return (abs(_left - _right) == 0);
		else return ((abs(_left - _right) == 0) || abs(_left - _right) == 32);
	}
};

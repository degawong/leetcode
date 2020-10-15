/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:25
 * @LastEditTime: 2020-10-15 20:24:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0005\0005.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        for(int i = 0; i < s.size(); ++i) {
            auto ls = Palindrome(s, i, i);
            auto rs = Palindrome(s, i, i + 1);
            ret = ret.size() > ls.size() ? ret : ls;
            ret = ret.size() > rs.size() ? ret : rs;
        }
        return ret;
    }
private:
	string Palindrome(string s, int l, int r) {
		while(l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        return s.substr(l + 1, r - l - 1);
	}
};

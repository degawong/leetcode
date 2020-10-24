/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:25
 * @LastEditTime: 2020-10-21 16:49:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0028\0028.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		if(haystack.size() < needle.size()) return -1;
		if(haystack.size() >= 0 && needle.size() == 0) return 0;
		if(haystack.size() == needle.size()) {
			if(!strcmp(haystack.data(), needle.data())) return 0;
			else return -1;
		}
		if(haystack.size() == 0 && needle.size() == 0) return 0;
		for(int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
			int j = 0;
			for(j = 0; j < needle.size(); ++j) {
				if(haystack[i + j] != needle[j]) break;
			}
			if(j == needle.size()) return i;
		}
		return -1;
    }
};

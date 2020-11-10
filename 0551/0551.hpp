/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:29
 * @LastEditTime: 2020-11-10 17:12:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0551\0551.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool checkRecord(string s) {
		int l = 0;
		int ab = { 0 };
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == 'L') ++l;
			else l = 0;
			if(s[i] == 'A') ++ab;
			if(l > 2 || ab > 1) return false;
		}
        return true;
    }
};

/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-11-06 13:47:01
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0165\0165.hpp
 */

#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		string item_1;
		string item_2;		
		stringstream s1(version1);
		stringstream s2(version2);
		while(1) {
			getline(s1, item_1, '.');
			getline(s2, item_2, '.');
			if(item_1.size() == 0 && item_2.size() == 0) return 0;
			auto _1 = item_1.size() > 0 ? stoi(item_1) : 0;
			auto _2 = item_2.size() > 0 ? stoi(item_2) : 0;
			item_1.clear();
			item_2.clear();
			if(_1 == _2) continue;
			if(_1 > _2) return 1;
			if(_1 < _2) return -1;
		}
		return 0;
    }
};

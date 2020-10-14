/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-10-14 15:31:25
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
    string longestCommonPrefix(vector<string>& strs) {

		if (strs.size() < 1) return string();

		string result("");

		for (int i = 0; i < strs[0].size(); ++i) {
			auto r = strs[0][i];
			for (int j = 1; j < strs.size(); ++j) {
				if (r != strs[j][i] || i >= strs[j].size()) {
					return result;
				}
			}
			result.push_back(r);
		}
		return result;

    }
};

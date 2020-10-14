/*
 * @Author: your name
 * @Date: 2020-09-30 14:33:38
 * @LastEditTime: 2020-09-30 14:37:46
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
    int lengthOfLongestSubstring(string s) {
		int temp = 0;
		int result = 0;
		int size = s.size();
		unordered_set<char> sub;
		int next = -1;
		for (int i = 0; i < size; ++i) {
			if (0 != i) {
				sub.erase(s[i - 1]);
			}
			while ((next < size - 1) && (!sub.count(s[next + 1]))) {
				sub.insert(s[(next++) + 1]);
			}
			result = max(next - i + 1, result);
		}
		return result;
    }
};

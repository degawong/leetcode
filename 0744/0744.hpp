/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-11-16 16:56:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0744\0744.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
		if(target >= letters[letters.size() - 1]) return letters[0];
		int left = 0;
		int right = letters.size();
		while(left < right - 1) {
			auto mid = (left + right) >> 1;
			if(letters[mid] <= target) left = mid;
			else if(letters[mid] > target) right = mid;
		}
		while(letters[left] <= target) ++left; 
		return letters[left];
    }
};

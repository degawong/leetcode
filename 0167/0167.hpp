/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:26
 * @LastEditTime: 2020-10-21 18:04:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0167\0167.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		int slow = 0;
		int fast = numbers.size() - 1;
		while(slow < fast) {
			if(numbers[slow] + numbers[fast] == target) {
				return { slow + 1, fast + 1 };
			} else if(numbers[slow] + numbers[fast] < target) {
				++slow;
			} else {
				--fast;
			}
		}
		return { -1, -1 };
    }
};

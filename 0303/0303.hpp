/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-10 14:35:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0303\0303.hpp
 */

#include <map>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
		v = nums;
		inter.resize(nums.size() + 1);
		inter[0] = 0;
		for(int i = 0; i < nums.size(); ++i) {
			inter[i + 1] += inter[i] + nums[i];
		}
    }
    
    int sumRange(int i, int j) {		
		return inter[j + 1] - inter[i];
    }
private:
	vector<int> v;
	vector<int> inter;
};

// class NumArray {
// public:
//     NumArray(vector<int>& nums) {
// 		v = nums;
//     }
    
//     int sumRange(int i, int j) {		
// 		auto key = pair(i, j);
// 		if(0 != m.count(pair(i, j))) return m[key];
// 		int sum = 0;
// 		for(int index = i; index <= j; ++index) {
// 			sum += v[index];
// 		}
// 		return m[key] = sum, sum;
//     }
// private:
// 	vector<int> v;
// 	map<pair<int, int>, int> m;
// };

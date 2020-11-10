/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:28
 * @LastEditTime: 2020-11-10 15:05:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0349\0349.hpp
 */

#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s;
        set<int> sv;
		vector<int> ret;		
		for(auto n : nums1) s.insert(n);
		for(auto n : nums2) {
			if(s.count(n) != 0) sv.insert(n);
		}
        for(auto n : sv) ret.push_back(n);
		return ret;
    }
};

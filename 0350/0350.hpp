/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:28
 * @LastEditTime: 2020-11-10 15:19:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0350\0350.hpp
 */

#include <map>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;        
		map<int, int> cm;
        map<int, int> fm;
		for(auto n : nums1) {
            ++cm[n];
        }
		for(auto n : nums2) {
			if(cm.count(n) != 0) ++fm[n];
		}
        for(auto& n : fm) {
			for(int i = 0; i < min(cm[n.first], fm[n.first]); ++i) ret.push_back(n.first);			
		}
		return ret;
    }
};

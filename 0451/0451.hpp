/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:29
 * @LastEditTime: 2020-11-16 16:27:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0451\0451.hpp
 */

#include <set>
#include <cmath>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
		string ret;
		unordered_map<char, int> um;
		priority_queue<ci, vector<ci>, op> pq;
		for(auto _ : s) ++um[_];
		for(auto& m : um) {
			pq.push(ci{m.second, m.first});
		}
		while(!pq.empty()) {
			auto n = pq.top(); pq.pop();
			for(int i = 0; i < n.count; ++i) {
				ret += n.c;
			}
		}
		return ret;
    }
private:
	struct ci {
		char c;
		int count;
		ci(int _count, char _c) {
			c = _c;
			count = _count;
		}
	};
	struct op {
		bool operator() (ci left, ci right) {
			return (left.count < right.count) || (left.count == right.count && left.c < right.c);
		}
	};
};
/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:30
 * @LastEditTime: 2020-11-11 17:58:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0692\0692.hpp
 */

#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct is {
	is(int _i, string _s) {
		i = _i;
		s = _s;
	}
	int i;
	string s;
};

struct wong {
	bool operator()(const is& left, const is& right) {
		return ((left.i > right.i) || (left.i == right.i && left.s < right.s));
	}
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ret;
		priority_queue<is, vector<is>, wong> pq;
		unordered_map<string, int> uo;
		for(auto& w : words) uo[w] += 1;
		for(auto& m : uo) {
			if(pq.size() >= k) {
				pq.push(is{ m.second, m.first });
				pq.pop();
			} else pq.push(is{ m.second, m.first });
		}
		while(!pq.empty()) {
			ret.push_back(pq.top().s); pq.pop();
		}
		reverse(ret.begin(), ret.end());
		return ret;
    }
};

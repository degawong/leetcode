/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:28
 * @LastEditTime: 2020-11-16 15:25:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0347\0347.hpp
 */

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
    vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> ret;
		priority_queue<mii, vector<mii>, cmii> pq;
		unordered_map<int, int> m;
		for(auto n : nums) ++m[n];
		for(auto& _ : m) {
			if(pq.size() < k) pq.push(mii{_.first, _.second});
			else {
				pq.push(mii{_.first, _.second});
				pq.pop();
			}
		}
		while(!pq.empty()) {
			auto top = pq.top(); pq.pop();
			ret.push_back(top.number);
		}
		return ret;
    }
private:
	struct mii {
		int count;		
		int number;
		mii(int n, int c) {
			count = c;			
			number = n;
		}
		bool operator< (const mii& other) {
			return (other.count < count) || (other.count == count && other.number < number);
		}
	};
	struct cmii {
		bool operator()(const mii& left, const mii& right) {
			return (left.count > right.count) || (left.count == right.count && left.number > right.number);
		}
	};
};

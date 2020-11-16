/*
 * @Author: your name
 * @Date: 2020-11-16 16:08:59
 * @LastEditTime: 2020-11-16 16:29:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\451.根据字符出现频率排序.cpp
 */
/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
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
// @lc code=end


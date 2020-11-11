/*
 * @Author: your name
 * @Date: 2020-11-10 14:56:59
 * @LastEditTime: 2020-11-10 15:05:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\349.两个数组的交集.cpp
 */
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
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
// @lc code=end


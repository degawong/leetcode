/*
 * @Author: your name
 * @Date: 2020-11-10 15:07:44
 * @LastEditTime: 2020-11-10 15:19:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\350.两个数组的交集-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
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
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-11-10 13:14:38
 * @LastEditTime: 2020-11-10 13:57:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\228.汇总区间.cpp
 */
/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		long left = 0;
		long right = 1;
		vector<string> ret;
		if(nums.size() == 0) return ret;
		if(nums.size() == 1) return ret.push_back(to_string(nums[0])), ret;
		while(right < nums.size()) {
			if(long(nums[right]) - long(nums[left]) != (right - left)) {
				if(right - left == 1) {
					ret.push_back(to_string(nums[left]));				
				}
				else {
					ret.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
				}
				left = right;
			}
			right += 1;
		}
		if(right - left == 1) {
			ret.push_back(to_string(nums[left]));				
		}
		else {
			ret.push_back(to_string(nums[left]) + "->" + to_string(nums[right - 1]));
		}
		return ret;
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-11-10 11:08:04
 * @LastEditTime: 2020-11-10 11:13:44
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\169.多数元素.cpp
 */
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		return nums[nums.size() >> 1];        
    }
};
// @lc code=end


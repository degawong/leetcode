/*
 * @Author: your name
 * @Date: 2020-10-30 16:41:26
 * @LastEditTime: 2020-10-30 16:54:06
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\11.盛最多水的容器.cpp
 */
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
		auto left = 0;
		auto ret = INT_MIN;
		auto right = height.size() - 1;
		while(left < right) {
			ret = max(ret, (int)(right - left) * min(height[left], height[right]));
			if(height[left] < height[right]) ++left;
			else --right;
		}
		return ret;
    }
};
// @lc code=end


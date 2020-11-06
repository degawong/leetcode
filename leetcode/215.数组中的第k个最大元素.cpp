/*
 * @Author: your name
 * @Date: 2020-11-05 15:05:17
 * @LastEditTime: 2020-11-05 15:43:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\215.数组中的第k个最大元素.cpp
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), std::greater_equal<int>());
		return nums[k - 1];
    }
};
// @lc code=end


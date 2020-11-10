/*
 * @Author: your name
 * @Date: 2020-11-09 17:24:29
 * @LastEditTime: 2020-11-09 17:35:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\704.二分查找.cpp
 */
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
		int mid = 0;
		int left = 0;
		int right = nums.size() - 1;				
		while(left <= right) {
			mid = left + (right - left) / 2;
			if(nums[mid] == target) return mid;
			if(nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
    }
};
// @lc code=end


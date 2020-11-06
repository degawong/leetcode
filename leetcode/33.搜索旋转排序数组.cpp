/*
 * @Author: your name
 * @Date: 2020-10-30 19:19:49
 * @LastEditTime: 2020-10-30 19:25:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\33.搜索旋转排序数组.cpp
 */
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto index = -1;
        auto anchor = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(nums[i] == target) index = i;            
            if(nums[i] > nums[i + 1]) anchor = i;
        }
        if(index = -1) return -1;
        else return 0;
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-10-30 19:31:53
 * @LastEditTime: 2020-10-30 19:59:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\34.在排序数组中查找元素的第一个和最后一个位置.cpp
 */
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return vector<int>{-1,-1};
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            auto mid = (left + right) / 2;
            if(nums[mid] > target) {
                right = mid;
            } else if(nums[mid] < target) {
                left = mid;
            } else {
                left = right = mid;
                while(left > 0 && nums[--left] == target);
                while((right < nums.size() - 1) && nums[++right] == target);
                if(nums[0] == target) left = 0; else left += 1;
                if(nums[nums.size() - 1] == target) right = nums.size() - 1; else right -= 1;
                return vector<int>{left,right};
            }
        }
        return vector<int>{-1,-1};
    }
};
// @lc code=end


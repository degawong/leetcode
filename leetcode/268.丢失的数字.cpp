/*
 * @Author: your name
 * @Date: 2020-10-23 16:24:29
 * @LastEditTime: 2020-10-23 16:26:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\268.丢失的数字.cpp
 */
/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto sum = 0;
        auto size = nums.size();
        for(auto n : nums) {
            sum += n;
        }
        return size * (size + 1) / 2 - sum;
    }
};
// @lc code=end


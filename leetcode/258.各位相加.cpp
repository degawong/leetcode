/*
 * @Author: your name
 * @Date: 2020-10-23 15:49:48
 * @LastEditTime: 2020-10-23 15:57:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\258.各位相加.cpp
 */
/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        int ret = 0;
        if(num < 10) return num;
        while(num > 0) {
            ret += num % 10;
            num = num / 10;
        }
        return addDigits(ret);
    }
};
// @lc code=end


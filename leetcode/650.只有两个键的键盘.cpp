/*
 * @Author: your name
 * @Date: 2020-11-09 14:46:14
 * @LastEditTime: 2020-11-09 14:58:07
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\650.只有两个键的键盘.cpp
 */
/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
		if(n & 1 != 0) return n;
		return min(1 + minSteps(n >> 1), n / 2);
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-10-23 15:15:40
 * @LastEditTime: 2020-10-23 15:36:49
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\231.2-的幂.cpp
 */
/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
		if(n == 1) return true;
		if(n == 0 || n % 2 != 0) return false;
		return isPowerOfTwo(n / 2);
    }
};
// @lc code=end


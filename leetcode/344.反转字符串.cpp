/*
 * @Author: your name
 * @Date: 2020-11-10 14:36:24
 * @LastEditTime: 2020-11-10 14:40:32
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\344.反转字符串.cpp
 */
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() == 0) return;
		int l = 0;
		int r = s.size() - 1;
		while(l < r) {
			swap(s[l++], s[r--]);
		}
    }
};
// @lc code=end


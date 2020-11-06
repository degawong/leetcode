/*
 * @Author: your name
 * @Date: 2020-11-06 13:49:50
 * @LastEditTime: 2020-11-06 14:11:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\171.excel表列序号.cpp
 */
/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
		int ret = 0;	
        for(int i = 0; i < s.size(); ++i) {
			ret = 26 * ret + (s[i] - 'A' + 1);
		}
		return ret;
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-11-10 16:12:21
 * @LastEditTime: 2020-11-10 16:19:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\387.字符串中的第一个唯一字符.cpp
 */
/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
		if(s.size() == 0) return 0;
		int l = 0;
		int r = s.size() - 1;
		for(int i = 0; i < s.size(); ++i) {
			for(int j = s.size() - 1; j >= 0; --j) {
				if(s[i] == s[j]) {
					r = j;
					break;
				}
			}
			if(i == r) return r;
		}
		return -1;
    }
};
// @lc code=end


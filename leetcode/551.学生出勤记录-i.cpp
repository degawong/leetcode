/*
 * @Author: your name
 * @Date: 2020-11-10 16:53:12
 * @LastEditTime: 2020-11-10 17:13:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\551.学生出勤记录-i.cpp
 */
/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
		int l = 0;
		int ab = { 0 };
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == 'L') ++l;
			else l = 0;
			if(s[i] == 'A') ++ab;
			if(l > 2 || ab > 1) return false;
		}
        return true;
    }
};
// @lc code=end


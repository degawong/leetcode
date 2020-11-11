/*
 * @Author: your name
 * @Date: 2020-11-10 17:15:21
 * @LastEditTime: 2020-11-10 17:27:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\557.反转字符串中的单词-iii.cpp
 */
/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        bool run = true;
        if(s.size() == 0) return s;
        int l = 0;
        int r = 0;
        while(run) {
            while(s[r] != ' ' && r < s.size()) ++r;
            int temp = r;
            if(r == s.size()) run = false;
            while (l < (r - 1)) {
                swap(s[l++], s[r-- - 1]);
            }
            l = r = temp + 1;
        }
        return s;
    }
};
// @lc code=end


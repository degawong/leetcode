/*
 * @Author: your name
 * @Date: 2020-11-10 15:45:05
 * @LastEditTime: 2020-11-10 16:07:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\383.赎金信.cpp
 */
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for (char c : magazine) hash[c - 'a'] += 1;
        for (char c : ransomNote) {
            if ((hash[c - 'a'] -= 1) < 0) return false;
		}
        return true;
    }
};
// @lc code=end


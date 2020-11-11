/*
 * @Author: your name
 * @Date: 2020-11-10 14:42:20
 * @LastEditTime: 2020-11-10 14:51:24
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\345.反转字符串中的元音字母.cpp
 */
/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() == 0) return s;
		int l = 0;
		int r = s.size() - 1;
		while(l < r) {
			if(!is_vowel(s[l])) {++l;continue;}
			if(!is_vowel(s[r])) {--r;continue;}
			swap(s[l++], s[r--]);
		}
		return s;
    }
private:
	bool is_vowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}
};
// @lc code=end


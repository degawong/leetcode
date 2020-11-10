/*
 * @Author: your name
 * @Date: 2020-10-30 20:04:20
 * @LastEditTime: 2020-11-10 10:26:58
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\67.二进制求和.cpp
 */
/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ret.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }
        if (carry) {
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        return ret;        
    }
};
// @lc code=end


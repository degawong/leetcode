/*
 * @Author: your name
 * @Date: 2020-10-23 16:29:59
 * @LastEditTime: 2020-10-23 16:44:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\278.第一个错误的版本.cpp
 */
/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid = (left + right) / 2;
        while(left < right && left != mid && right != mid) {
            if(isBadVersion(mid)) {
                right = mid;
                mid = (left + right) / 2;
            } else {
                left = mid;
                mid = (left + right) / 2;                
            }
        }
		if(isBadVersion(mid)) return mid;
        else return right;
    }
};
// @lc code=end


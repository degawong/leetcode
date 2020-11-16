/*
 * @Author: your name
 * @Date: 2020-11-16 16:40:57
 * @LastEditTime: 2020-11-16 16:56:41
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\744.寻找比目标字母大的最小字母.cpp
 */
/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
		if(target >= letters[letters.size() - 1]) return letters[0];
		int left = 0;
		int right = letters.size();
		while(left < right - 1) {
			auto mid = (left + right) >> 1;
			if(letters[mid] <= target) left = mid;
			else if(letters[mid] > target) right = mid;
		}
		while(letters[left] <= target) ++left; 
		return letters[left];
    }
};
// @lc code=end


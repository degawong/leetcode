/*
 * @Author: your name
 * @Date: 2020-11-10 10:30:54
 * @LastEditTime: 2020-11-10 10:53:08
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\119.杨辉三角-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> ret(rowIndex + 1, 1);
        if(rowIndex == 0) return vector<int>(1, 1);
        if(rowIndex == 1) return vector<int>(2, 1);
		for(int i = 2; i <= rowIndex; ++i) {
			for(int j = i - 1; j > 0; --j) {
				ret[j] += ret[j - 1];
			}
		}
       	return ret;
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-10-30 16:14:01
 * @LastEditTime: 2020-10-30 16:23:55
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\908.最小差值-i.cpp
 */
/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
		int _max = INT_MIN;
		int _min = INT_MAX;
		for(auto r : A) {
			if(_max < r) _max = r;
			if(_min > r) _min = r;
		}
		return max(0, _max - _min - 2 * K);
    }
};
// @lc code=end


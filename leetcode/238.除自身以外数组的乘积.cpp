/*
 * @Author: your name
 * @Date: 2020-11-06 15:24:56
 * @LastEditTime: 2020-11-06 15:46:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\238.除自身以外数组的乘积.cpp
 */
/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int size = nums.size();
		vector<int> ret(size, 0);
		vector<int> lm(size, nums[0]);
		vector<int> rm(size, nums[size - 1]);
		for(int i = 1; i < size; ++i) {
			lm[i] = lm[i - 1] * nums[i];
			rm[size - i - 1] = rm[size - i] * nums[size - i - 1];
		}
		for(int i = 1; i < size - 1; ++i) ret[i] = lm[i - 1] * rm[i + 1];
		ret[0] = rm[1];
		ret[size - 1] = lm[size - 1 - 1];
        return ret;
    }
};
// @lc code=end


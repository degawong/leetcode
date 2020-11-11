/*
 * @Author: your name
 * @Date: 2020-11-10 14:02:24
 * @LastEditTime: 2020-11-10 14:35:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\303.区域和检索-数组不可变.cpp
 */
/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
		v = nums;
		inter.resize(nums.size() + 1);
		inter[0] = 0;
		for(int i = 0; i < nums.size(); ++i) {
			inter[i + 1] += inter[i] + nums[i];
		}
    }
    
    int sumRange(int i, int j) {		
		return inter[j + 1] - inter[i];		
    }
private:
	vector<int> v;
	vector<int> inter;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end


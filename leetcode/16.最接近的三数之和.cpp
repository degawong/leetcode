/*
 * @Author: your name
 * @Date: 2020-10-30 17:00:18
 * @LastEditTime: 2020-10-30 17:31:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\16.最接近的三数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		auto ret = INT_MAX;
		auto diff = INT_MAX;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size() - 2; ++i) {
			auto left = i + 1;
			auto right = nums.size() - 1;
            while(left < right) {
                auto temp = nums[i] + nums[left] + nums[right];
                if(temp < target) ++left;
                if(temp > target) --right;
                if(temp == target) return target;
                if(diff > abs(target - temp)) ret = temp, diff = abs(target - temp);
            }
		}
		return ret;
    }
};
// @lc code=end


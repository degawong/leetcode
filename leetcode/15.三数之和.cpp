/*
 * @Author: your name
 * @Date: 2020-10-30 17:36:04
 * @LastEditTime: 2020-10-30 17:47:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\15.三数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size() - 2; ++i) {
			auto left = i + 1;
			auto right = nums.size() - 1;
            while(left < right) {
				if(nums[left] == nums[left + 1]) {++left; continue;}
				if(nums[right] == nums[right - 1]) {--right; continue;} 
                auto temp = nums[i] + nums[left] + nums[right];
                if(temp < 0) ++left;
                if(temp > 0) --right;
				if(temp == 0) ret.push_back(vector<int>{nums[i], nums[left++], nums[right--]});
            }
		}
		return ret;
    }
};
// @lc code=end


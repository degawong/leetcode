/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-10-16 18:12:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0219\0219.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
// 		if(nums.size() == 0) return false;	
// 		for(int i = 0; i < nums.size() - 1; ++i) {
// 			for(int j = 1; j <= min(k, int(nums.size() - i - 1)); ++j) {
// 				if(nums[i] == nums[i + j]) return true;
// 			}
// 		}
//         return false;
//     }
// };

class Solution {
public:
	// beautiful
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            if (!st.insert(nums[i]).second) return true;
            if (st.size() > k) st.erase(nums[i-k]);
        }
        return false;
    }
};

// ：https://leetcode-cn.com/problems/contains-duplicate-ii/solution/hua-dong-chuang-kou-5xing-dai-ma-jie-jue-shi-jian-/


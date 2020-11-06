/*
 * @Author: your name
 * @Date: 2020-11-06 13:13:18
 * @LastEditTime: 2020-11-06 13:47:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\165.比较版本号.cpp
 */
/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
		string item_1;
		string item_2;		
		stringstream s1(version1);
		stringstream s2(version2);
		while(1) {
			getline(s1, item_1, '.');
			getline(s2, item_2, '.');
			if(item_1.size() == 0 && item_2.size() == 0) return 0;
			auto _1 = item_1.size() > 0 ? stoi(item_1) : 0;
			auto _2 = item_2.size() > 0 ? stoi(item_2) : 0;
			item_1.clear();
			item_2.clear();
			if(_1 == _2) continue;
			if(_1 > _2) return 1;
			if(_1 < _2) return -1;
		}
		return 0;
    }
};
// @lc code=end


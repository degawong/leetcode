/*
 * @Author: your name
 * @Date: 2020-11-02 16:54:05
 * @LastEditTime: 2020-11-02 17:26:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\63.不同路径-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        vector<vector<int>> dp(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, 0));
		for(int i = 1; i < obstacleGrid.size() + 1; ++i) {
			for(int j = 1; j < obstacleGrid[0].size() + 1; ++j) {
				if(i == 1 && j == 1) {
					if(obstacleGrid[0][0] == 1) return 0;
					else dp[1][1] = 1;
				} else {
					if (obstacleGrid[i-1][j-1] == 1) dp[i][j] = 0;
                    else dp[i][j] = dp[i-1][j] + dp[i][j-1];
				}
			}
		}
		return dp[obstacleGrid.size()][obstacleGrid[0].size()];  
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-10-20 16:04:47
 * @LastEditTime: 2020-11-02 17:27:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0063\0063.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

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

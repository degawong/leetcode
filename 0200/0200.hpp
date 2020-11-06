/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:27
 * @LastEditTime: 2020-11-06 09:24:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0200\0200.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		int ret = 0;
		if(grid.size() == 0 || grid[0].size() == 0) return ret;
		for(int i = 0; i < grid.size(); ++i) {
			for(int j = 0; j < grid[0].size(); ++j) {
				if(grid[i][j] == '1') {
					++ret;
					dfs(grid, i, j);
				}
			}
		}
		return ret;
    }
private:
	void dfs(vector<vector<char>>& grid, int i, int j) {
		grid[i][j] = '0';
		auto p_i = max(0, i - 1);
		auto p_j = max(0, j - 1);		
		auto n_i = min(i + 1, int(grid.size()) - 1);
		auto n_j = min(j + 1, int(grid[0].size()) - 1);
		if(grid[p_i][j] == '1') dfs(grid, p_i, j);
		if(grid[n_i][j] == '1') dfs(grid, n_i, j);
		if(grid[i][p_j] == '1') dfs(grid, i, p_j);
		if(grid[i][n_j] == '1') dfs(grid, i, n_j);
	}
};

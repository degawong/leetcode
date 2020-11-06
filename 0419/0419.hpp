/*
 * @Author: your name
 * @Date: 2020-10-14 16:04:28
 * @LastEditTime: 2020-11-06 17:19:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\0419\0419.hpp
 */

#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
		auto ret = 0;
		if(board.size() == 0 || board[0].size() == 0) return ret;
		for(int i = 0; i < board.size(); ++i) {
			for(int j = 0; j < board[0].size(); ++j) {
				if(board[i][j] == 'X') {
					ret += 1;
					wipe(board, i, j);
				}
			}
		}
		return ret;
    }
private:
	void wipe(vector<vector<char>>& board, int i, int j) {
		board[i][j] = '.';
		auto p_i = max(0, i - 1);
		auto p_j = max(0, j - 1);
		auto a_i = min(i + 1, int(board.size() - 1));
		auto a_j = min(j + 1, int(board[0].size() - 1));
		if(board[p_i][j] == 'X') wipe(board, p_i, j);
		if(board[i][p_j] == 'X') wipe(board, i, p_j);
		if(board[a_i][j] == 'X') wipe(board, a_i, j);
		if(board[i][a_j] == 'X') wipe(board, i, a_j);
	}
};


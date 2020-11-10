/*
 * @Author: your name
 * @Date: 2020-11-06 17:04:48
 * @LastEditTime: 2020-11-06 17:19:29
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\419.甲板上的战舰.cpp
 */
/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
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
// @lc code=end


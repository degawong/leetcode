/*
 * @Author: your name
 * @Date: 2020-11-05 17:27:40
 * @LastEditTime: 2020-11-16 17:47:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\leetcode\130.被围绕的区域.cpp
 */
/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(board[i][j] == 'O') board[i][j] = 'X';
        else return;
        dfs(board, max(0, i - 1), j);
        dfs(board, min(int(board.size() - 1), i + 1), j);
        dfs(board, i, max(0, j - 1));
        dfs(board, i, min(j + 1, int(board[0].size() - 1)));
    }

    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        for(int i = 0; i < board.size(); ++i) {
            if(board[i][0] == 'O') mark(board, i, 0);
            if(board[i][board[0].size() - 1] == 'O') mark(board, i, board[0].size() - 1);
        }
        for(int i = 0; i < board[0].size(); ++i) {
            if(board[0][i] == 'O') mark(board, 0, i);
            if(board[board.size() - 1][i] == 'O') mark(board, board.size() - 1, i);            
        }
        for(int i = 1; i < board.size() - 1; ++i) {
            for(int j = 1; j < board[0].size() - 1; ++j) {
                if(board[i][j] == 'O') dfs(board, i, j);
            }
        }
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == 'M') board[i][j] = 'O';
            }
        }
    }
private:
    void mark(vector<vector<char>>& board, int i, int j) {
        if(board[i][j] == 'O') board[i][j] = 'M';
        else return;
        mark(board, max(0, i - 1), j);
        mark(board, min(int(board.size()) - 1, i + 1), j);
        mark(board, i, max(0, j - 1));
        mark(board, i, min(int(board[0].size()) - 1, j + 1));        
    }
};
// @lc code=end


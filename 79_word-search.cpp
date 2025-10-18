#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            vector<pair<int, int>> starting_points;
            int ROWS = board.size(), COLS = board[0].size();
            for(int n = 0; n < ROWS; n++) {
                for(int m = 0; m < COLS; m++) {
                    if(dfs(0, n, m, word, board)) return true;
                }
            }
            return false;
        }
        
        bool dfs(int i, int row, int col, string& word, vector<vector<char>>& board) {
            if (i == word.size()) return true;
            if (row < 0 || col < 0 || i >= word.size() ||
            row >= board.size() || col >= board[0].size() ||
            board[row][col] == '#' ||
            word[i] != board[row][col]) {
                return false;
            }
            int temp = board[row][col];
            // cout << row << ", " << col << endl;
            board[row][col] = '#';
            bool IDK = dfs(i + 1, row + 1, col, word, board) ||
                dfs(i + 1, row - 1, col, word, board) ||
                dfs(i + 1, row, col + 1, word, board) ||
                dfs(i + 1, row, col - 1, word, board);
            board[row][col] = temp;
            return IDK;
        }
};

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    string word = "ABCESEEEFS";
    Solution sln = Solution();
    bool hmm = sln.exist(board, word);
    cout << hmm << endl;
}

class Solution {
  int r = 0;
  int c = 0;

 public:
  void solve(vector<vector<char>>& board) {
    // search for all O's on the boundary
    // if X or # then continue
    // else mark all neigbouring O's as #
    r = board.size();

    c = board[0].size();
    for (int i = 0; i < c; i++) {
      if (board[0][i] == 'O') {
        markneig(board, 0, i);
      }
      if (board[r - 1][i] == 'O') {
        markneig(board, r - 1, i);
      }
    }
    for (int i = 1; i < r - 1; i++) {
      if (board[i][0] == 'O') {
        markneig(board, i, 0);
      }
      if (board[i][c - 1] == 'O') {
        markneig(board, i, c - 1);
      }
    }
    for (auto& x : board) {
      for (auto& y : x) {
        if (y == 'O') y = 'X';
        if (y == '#') y = 'O';
      }
    }
  }
  void markneig(vector<vector<char>>& board, int a, int b) {
    if (a < 0 || b < 0 || a >= r || b >= c) return;
    if (board[a][b] == 'X' || board[a][b] == '#') return;
    board[a][b] = '#';
    markneig(board, a + 1, b);
    markneig(board, a - 1, b);
    markneig(board, a, b + 1);
    markneig(board, a, b - 1);
  }
};
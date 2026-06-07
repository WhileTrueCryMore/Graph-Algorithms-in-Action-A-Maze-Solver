class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<int> queen(n, -1);  // queen[row] = col
    nQueens(queen, 0, n, ans);
    return ans;
  }

  void nQueens(vector<int>& queen, int row, int n,
               vector<vector<string>>& ans) {
    if (row == n) {
      vector<string> board(n, string(n, '.'));

      for (int r = 0; r < n; r++)
        board[r][queen[r]] = 'Q';

      ans.push_back(board);
      return;
    }

    for (int col = 0; col < n; col++) {
      if (isSafe(queen, row, col)) {
        queen[row] = col;
        nQueens(queen, row + 1, n, ans);
        queen[row] = -1;
      }
    }
  }

  bool isSafe(const vector<int>& queen, int row, int col) {
    for (int r = 0; r < row; r++) {
      // same column
      if (queen[r] == col)
        return false;

      // same diagonal
      if (abs(queen[r] - col) == abs(r - row))
        return false;
    }

    return true;
  }
};
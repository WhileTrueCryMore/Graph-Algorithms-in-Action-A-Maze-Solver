class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int isl_count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '0') continue;
        isl_count++;
        visit_isl(grid, i, j, m, n);
      }
    }
    return isl_count;
  }
  void visit_isl(vector<vector<char>>& grid, int i, int j, int m, int n) {
    if (i == m || j == n || i < 0 || j < 0) {
      return;
    }
    if (grid[i][j] == '0') return;
    grid[i][j] = '0';
    visit_isl(grid, i + 1, j, m, n);
    visit_isl(grid, i, j + 1, m, n);
    visit_isl(grid, i, j - 1, m, n);
    visit_isl(grid, i - 1, j, m, n);
  }
};
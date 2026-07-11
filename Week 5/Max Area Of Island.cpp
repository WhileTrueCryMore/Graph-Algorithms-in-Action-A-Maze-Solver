class Solution {
  int m = 0;
  int n = 0;

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_ar = 0;
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) continue;
        int ar = 0;
        visit_isl(grid, i, j, ar);
        max_ar = max(ar, max_ar);
      }
    }
    return max_ar;
  }
  void visit_isl(vector<vector<int>>& grid, int i, int j, int& ar) {
    if (i >= m || j >= n || i < 0 || j < 0) {
      return;
    }
    if (grid[i][j] == 0) return;
    grid[i][j] = 0;
    ar++;
    visit_isl(grid, i + 1, j, ar);
    visit_isl(grid, i, j + 1, ar);
    visit_isl(grid, i, j - 1, ar);
    visit_isl(grid, i - 1, j, ar);
  }
};

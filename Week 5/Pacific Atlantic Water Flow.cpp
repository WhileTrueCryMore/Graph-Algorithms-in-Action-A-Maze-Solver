class Solution {
  int m, n;
  vector<int> dx = {1, -1, 0, 0};
  vector<int> dy = {0, 0, 1, -1};

  void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
    vis[i][j] = true;

    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];

      if (x < 0 || x >= m || y < 0 || y >= n)
        continue;

      if (vis[x][y])
        continue;

      if (heights[x][y] < heights[i][j])
        continue;

      dfs(x, y, heights, vis);
    }
  }

 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    m = heights.size();
    n = heights[0].size();

    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    // Pacific
    for (int j = 0; j < n; j++)
      if (!pacific[0][j])
        dfs(0, j, heights, pacific);

    for (int i = 0; i < m; i++)
      if (!pacific[i][0])
        dfs(i, 0, heights, pacific);

    // Atlantic
    for (int j = 0; j < n; j++)
      if (!atlantic[m - 1][j])
        dfs(m - 1, j, heights, atlantic);

    for (int i = 0; i < m; i++)
      if (!atlantic[i][n - 1])
        dfs(i, n - 1, heights, atlantic);

    vector<vector<int>> ans;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (pacific[i][j] && atlantic[i][j])
          ans.push_back({i, j});
      }
    }

    return ans;
  }
};
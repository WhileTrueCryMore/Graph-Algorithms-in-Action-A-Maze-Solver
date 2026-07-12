class Solution {
  int m, n;
  vector<int> dirx = {1, -1, 0, 0};
  vector<int> diry = {0, 0, 1, -1};

 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    m = mat.size();
    n = mat[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> ans(m, vector<int>(n, 0));
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          q.push({i, j});
          visited[i][j] = 1;
        }
      }
    }
    while (!q.empty()) {
      auto [a, b] = q.front();
      q.pop();
      for (int k = 0; k < 4; k++) {
        int x = a + dirx[k];
        int y = b + diry[k];
        if (!(x < 0 || x >= m || y < 0 || y >= n) &&
            !visited[x][y]) {
          ans[x][y] = ans[a][b] + 1;
          q.push({x, y});
          visited[x][y] = 1;
        }
      }
    }
    return ans;
  }
};
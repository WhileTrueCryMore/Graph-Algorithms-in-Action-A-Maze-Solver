class Solution {
  int m = 0;
  int n = 0;

 public:
  int orangesRotting(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int time = 0;
    int fresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1)
          fresh++;
        else if (grid[i][j] == 2)
          q.push({i, j});
      }
    }
    while (!q.empty()) {
      int s = q.size();
      for (int i = 0; i < s; i++) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x + 1 < m && grid[x + 1][y] == 1) {
          q.push({x + 1, y});
          grid[x + 1][y] = 2;
          fresh--;
        }
        if (y + 1 < n && grid[x][y + 1] == 1) {
          q.push({x, y + 1});
          grid[x][y + 1] = 2;
          fresh--;
        }
        if (x - 1 >= 0 && grid[x - 1][y] == 1) {
          q.push({x - 1, y});
          grid[x - 1][y] = 2;
          fresh--;
        }
        if (y - 1 >= 0 && grid[x][y - 1] == 1) {
          q.push({x, y - 1});
          grid[x][y - 1] = 2;
          fresh--;
        }
      }
      if (q.empty()) {
        break;
      }
      time++;
    }
    if (fresh) return -1;
    return time;
  }
};
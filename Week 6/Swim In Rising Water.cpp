class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<vector<int>> time(n, vector<int>(n, INT_MAX));
    time[0][0] = grid[0][0];

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        pq;

    pq.push({grid[0][0], {0, 0}});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
      auto [tm, cell] = pq.top();
      auto [x, y] = cell;
      pq.pop();

      if (tm > time[x][y]) continue;

      if (x == n - 1 && y == n - 1)
        return tm;

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
          int newTime = max(tm, grid[nx][ny]);

          if (newTime < time[nx][ny]) {
            time[nx][ny] = newTime;
            pq.push({newTime, {nx, ny}});
          }
        }
      }
    }

    return -1;
  }
};
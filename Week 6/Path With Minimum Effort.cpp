class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<>>
        pq;

    effort[0][0] = 0;
    pq.push({0, {0, 0}});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
      auto [d, cell] = pq.top();
      pq.pop();

      int x = cell.first;
      int y = cell.second;

      if (d > effort[x][y])
        continue;

      if (x == n - 1 && y == m - 1)
        return d;

      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;

        int edge = abs(heights[x][y] - heights[nx][ny]);
        int newEffort = max(d, edge);

        if (newEffort < effort[nx][ny]) {
          effort[nx][ny] = newEffort;
          pq.push({newEffort, {nx, ny}});
        }
      }
    }

    return 0;
  }
};
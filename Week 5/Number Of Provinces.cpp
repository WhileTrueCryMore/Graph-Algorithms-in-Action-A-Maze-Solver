class Solution {
  int n = 0;

 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    n = isConnected.size();
    int counter = 0;
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++) {
      if (visited[i]) {
        continue;
      }
      counter++;
      dfs(isConnected, i, visited);
    }
    return counter;
  }

  void dfs(vector<vector<int>>& Graph, int i, vector<bool>& visited) {
    visited[i] = 1;
    for (int j = 0; j < n; j++) {
      if (Graph[i][j] && !visited[j]) {
        dfs(Graph, j, visited);
      }
    }
  }
};
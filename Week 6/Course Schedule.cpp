class Solution {
  bool isCycle(int u, vector<vector<int>>& adj, vector<bool>& visited,
               vector<bool>& pathvis) {
    visited[u] = 1;
    pathvis[u] = 1;
    for (int v : adj[u]) {
      if (!visited[v]) {
        if (isCycle(v, adj, visited, pathvis))
          return true;
      } else if (pathvis[v])
        return true;
    }
    pathvis[u] = 0;
    return false;
  }

 public:
  bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<bool> visited(n, 0);
    vector<bool> pathvis(n, 0);
    vector<vector<int>> adj(n);
    for (auto& p : prerequisites) {
      adj[p[1]].push_back(p[0]);
    }
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        if (isCycle(i, adj, visited, pathvis))
          return false;
      }
    }
    return true;
  }
};
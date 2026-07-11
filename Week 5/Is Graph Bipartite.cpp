class Solution {
  int V = 0;

 public:
  bool isBipartite(vector<vector<int>>& graph) {
    V = graph.size();
    vector<int> colored(V, -1);
    for (int u = 0; u < V; u++) {
      if (colored[u] != -1) {
        continue;
      }
      colored[u] = 0;
      if (!dfs(graph, u, colored)) {
        return false;
      }
    }
    return true;
  }

  bool dfs(vector<vector<int>>& graph, int u, vector<int>& colored) {
    for (auto& v : graph[u]) {
      if (colored[u] == colored[v]) {
        return false;
      }
      if (colored[v] == -1) {
        colored[v] = 1 - colored[u];
        if (!dfs(graph, v, colored)) return false;
      }
    }
    return true;
  }
};
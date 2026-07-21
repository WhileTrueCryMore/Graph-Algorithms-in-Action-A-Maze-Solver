class Solution {
 public:
  vector<vector<int>> graph;
  vector<int> tin, low;
  vector<vector<int>> bridges;
  int timer = 0;

  void dfs(int u, int parent) {
    tin[u] = low[u] = timer++;

    for (int v : graph[u]) {
      if (v == parent)
        continue;

      if (tin[v] != -1) {
        // Back edge
        low[u] = min(low[u], tin[v]);
      } else {
        dfs(v, u);

        low[u] = min(low[u], low[v]);

        if (low[v] > tin[u])
          bridges.push_back({u, v});
      }
    }
  }

  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>>& connections) {
    graph.assign(n, {});
    tin.assign(n, -1);
    low.assign(n, -1);

    for (auto& e : connections) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    dfs(0, -1);

    return bridges;
  }
};
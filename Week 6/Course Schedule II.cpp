class Solution {
 public:
  vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    vector<int> ans;
    for (auto& p : prerequisites) {
      adj[p[1]].push_back(p[0]);
      indeg[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (indeg[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto& v : adj[u]) {
        indeg[v]--;
        if (indeg[v] == 0) {
          q.push(v);
        }
      }
      ans.push_back(u);
    }
    if (ans.size() < n) {
      return {};
    } else
      return ans;
  }
};
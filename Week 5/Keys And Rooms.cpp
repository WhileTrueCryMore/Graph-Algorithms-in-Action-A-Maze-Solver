class Solution {
  int n;

  void dfs(int i, vector<bool>& visited, vector<vector<int>>& rooms) {
    visited[i] = 1;
    for (auto& x : rooms[i]) {
      if (!visited[x]) dfs(x, visited, rooms);
    }
  }

 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    n = rooms.size();
    vector<bool> visited(n, 0);
    dfs(0, visited, rooms);
    for (auto x : visited) {
      if (!x) return false;
    }
    return true;
  }
};
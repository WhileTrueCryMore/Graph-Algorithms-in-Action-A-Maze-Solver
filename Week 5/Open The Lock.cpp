class Solution {
  int m;

 public:
  int openLock(vector<string>& deadends, string target) {
    m = deadends.size();
    vector<bool> visited(10000, 0);
    for (auto& s : deadends) {
      visited[stoi(s)] = true;
    }
    if (visited[0]) {
      return -1;
    }
    queue<string> q;
    int level = 0;
    q.push("0000");
    visited[0] = 1;
    while (!q.empty()) {
      int s = q.size();
      for (int j = 0; j < s; j++) {
        string k = q.front();
        if (k == target) {
          return level;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
          string s = k;
          s[i] = (s[i] - '0' + 1) % 10 + '0';
          if (!visited[stoi(s)]) {
            q.push(s);
            visited[stoi(s)] = 1;
          }
          s = k;
          s[i] = (s[i] - '0' + 9) % 10 + '0';
          if (!visited[stoi(s)]) {
            q.push(s);
            visited[stoi(s)] = 1;
          }
        }
      }
      level++;
    }
    return -1;
  }
};
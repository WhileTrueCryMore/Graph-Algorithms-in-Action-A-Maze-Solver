class DSU {
 public:
  vector<int> parent, sz;

  int addNode() {
    int id = parent.size();
    parent.push_back(id);
    sz.push_back(1);
    return id;
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return;

    if (sz[u] < sz[v])
      swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
  }
};

class Solution {
 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    DSU dsu;

    unordered_map<string, int> emailToId;
    unordered_map<string, string> emailToName;

    for (auto& acc : accounts) {
      string name = acc[0];

      for (int i = 1; i < acc.size(); i++) {
        if (!emailToId.count(acc[i])) {
          emailToId[acc[i]] = dsu.addNode();
          emailToName[acc[i]] = name;
        }
      }

      int first = emailToId[acc[1]];

      for (int i = 2; i < acc.size(); i++) {
        dsu.unite(first, emailToId[acc[i]]);
      }
    }

    unordered_map<int, vector<string>> groups;

    for (auto& [email, id] : emailToId) {
      groups[dsu.find(id)].push_back(email);
    }

    vector<vector<string>> ans;

    for (auto& [root, emails] : groups) {
      sort(emails.begin(), emails.end());

      vector<string> curr;
      curr.push_back(emailToName[emails[0]]);
      curr.insert(curr.end(), emails.begin(), emails.end());

      ans.push_back(curr);
    }

    return ans;
  }
};
#include <bits/stdc++.h>
using namespace std;

struct Grid {
  int R, C;
  vector<string> cells;
};

struct Result {
  int cost;
  vector<pair<int, int>> path;
  int expanded;
};

int cellCost(char ch) {
  return (ch >= '0' && ch <= '9') ? ch - '0' : 1;
}

int manhattan(int r1, int c1, int r2, int c2) {
  return abs(r1 - r2) + abs(c1 - c2);
}

vector<pair<int, int>> neighbours(const Grid& g, int r, int c) {
  vector<pair<int, int>> result;
  int rowMove[4] = {-1, 1, 0, 0};
  int colMove[4] = {0, 0, -1, 1};
  for (int k = 0; k < 4; k++) {
    int nr = r + rowMove[k];
    int nc = c + colMove[k];
    if (nr < 0 || nr >= g.R || nc < 0 || nc >= g.C) {
      continue;
    }
    if (g.cells[nr][nc] == '#') {
      continue;
    }
    result.push_back({nr, nc});
  }
  return result;
}

vector<pair<int, int>> buildPathFromParents(const Grid& g, const vector<int>& parent,
                                            int startIndex, int endIndex) {
  vector<pair<int, int>> path;
  int cur = endIndex;
  while (cur != -1) {
    path.push_back({cur / g.C, cur % g.C});
    if (cur == startIndex) {
      break;
    }
    cur = parent[cur];
  }
  reverse(path.begin(), path.end());
  return path;
}

Result bfs(const Grid& g, pair<int, int> s, pair<int, int> t) {
  int total = g.R * g.C;
  vector<int> dist(total, -1);
  vector<int> parent(total, -1);

  int startIndex = s.first * g.C + s.second;
  int endIndex = t.first * g.C + t.second;

  queue<pair<int, int>> q;
  dist[startIndex] = 0;
  q.push(s);

  int expanded = 0;
  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    expanded++;

    int u = r * g.C + c;
    if (u == endIndex) {
      break;
    }

    for (auto& nb : neighbours(g, r, c)) {
      int nr = nb.first;
      int nc = nb.second;
      int v = nr * g.C + nc;
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        parent[v] = u;
        q.push({nr, nc});
      }
    }
  }

  Result res;
  res.expanded = expanded;
  if (dist[endIndex] == -1) {
    res.cost = INT_MAX;
    return res;
  }
  res.cost = dist[endIndex];
  res.path = buildPathFromParents(g, parent, startIndex, endIndex);
  return res;
}

Result dijkstra(const Grid& g, pair<int, int> s, pair<int, int> t) {
  int total = g.R * g.C;
  vector<int> dist(total, INT_MAX);
  vector<int> parent(total, -1);
  int startIndex = s.first * g.C + s.second;
  int endIndex = t.first * g.C + t.second;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[startIndex] = 0;
  pq.push({0, startIndex});

  int expanded = 0;
  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (d != dist[u]) {
      continue;
    }
    expanded++;

    if (u == endIndex) {
      break;
    }

    int ur = u / g.C;
    int uc = u % g.C;
    for (auto& nb : neighbours(g, ur, uc)) {
      int nr = nb.first;
      int nc = nb.second;
      int v = nr * g.C + nc;
      int stepCost = cellCost(g.cells[nr][nc]);
      if (dist[u] + stepCost < dist[v]) {
        dist[v] = dist[u] + stepCost;
        parent[v] = u;
        pq.push({dist[v], v});
      }
    }
  }

  Result res;
  res.expanded = expanded;
  if (dist[endIndex] == INT_MAX) {
    res.cost = INT_MAX;
    return res;
  }
  res.cost = dist[endIndex];
  res.path = buildPathFromParents(g, parent, startIndex, endIndex);
  return res;
}

Result astar(const Grid& g, pair<int, int> s, pair<int, int> t) {
  int total = g.R * g.C;
  vector<int> dist(total, INT_MAX);
  vector<int> parent(total, -1);
  int startIndex = s.first * g.C + s.second;
  int endIndex = t.first * g.C + t.second;

  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;
  dist[startIndex] = 0;
  pq.push({manhattan(s.first, s.second, t.first, t.second), {0, startIndex}});

  int expanded = 0;
  while (!pq.empty()) {
    int costSoFar = pq.top().second.first;
    int u = pq.top().second.second;
    pq.pop();

    if (costSoFar != dist[u]) {
      continue;
    }
    expanded++;

    if (u == endIndex) {
      break;
    }

    int ur = u / g.C;
    int uc = u % g.C;
    for (auto& nb : neighbours(g, ur, uc)) {
      int nr = nb.first;
      int nc = nb.second;
      int v = nr * g.C + nc;
      int stepCost = cellCost(g.cells[nr][nc]);
      if (dist[u] + stepCost < dist[v]) {
        dist[v] = dist[u] + stepCost;
        parent[v] = u;
        pq.push({dist[v] + manhattan(nr, nc, t.first, t.second), {dist[v], v}});
      }
    }
  }

  Result res;
  res.expanded = expanded;
  if (dist[endIndex] == INT_MAX) {
    res.cost = INT_MAX;
    return res;
  }
  res.cost = dist[endIndex];
  res.path = buildPathFromParents(g, parent, startIndex, endIndex);
  return res;
}

int lastOrderingsTried = 0;

void tryOrders(const vector<vector<int>>& distTable, const vector<int>& coinList,
               vector<bool>& used, vector<int>& order,
               int lastPoint, int costSoFar, int goalPoint,
               int& bestCost, vector<int>& bestOrder, int& tried) {
  if (costSoFar >= bestCost) {
    return;
  }

  int numCoins = coinList.size();
  if ((int)order.size() == numCoins) {
    tried++;
    int total = costSoFar + distTable[lastPoint][goalPoint];
    if (total < bestCost) {
      bestCost = total;
      bestOrder = order;
    }
    return;
  }

  for (int i = 0; i < numCoins; i++) {
    if (!used[i]) {
      used[i] = true;
      order.push_back(coinList[i]);
      tryOrders(distTable, coinList, used, order, coinList[i],
                costSoFar + distTable[lastPoint][coinList[i]], goalPoint,
                bestCost, bestOrder, tried);
      order.pop_back();
      used[i] = false;
    }
  }
}

int bestOrder(const vector<vector<int>>& distTable, int startPoint, int goalPoint,
              vector<int>& outOrder) {
  int size = distTable.size();
  vector<int> coinList;
  for (int i = 0; i < size; i++) {
    if (i != startPoint && i != goalPoint) {
      coinList.push_back(i);
    }
  }

  int numCoins = coinList.size();
  vector<bool> used(numCoins, false);
  vector<int> order;
  int bestCost = INT_MAX;
  vector<int> bestOrder;
  int tried = 0;

  tryOrders(distTable, coinList, used, order, startPoint, 0, goalPoint,
            bestCost, bestOrder, tried);

  outOrder = bestOrder;
  lastOrderingsTried = tried;
  return bestCost;
}

struct MazeData {
  Grid grid;
  pair<int, int> start;
  pair<int, int> goal;
  vector<pair<int, int>> keyPoints;
};

bool loadMaze(const string& filename, MazeData& data) {
  ifstream fin(filename.c_str());
  if (!fin) {
    return false;
  }

  fin >> data.grid.R >> data.grid.C;
  fin >> data.start.first >> data.start.second;
  fin >> data.goal.first >> data.goal.second;
  fin.ignore();

  data.grid.cells.resize(data.grid.R);
  for (int i = 0; i < data.grid.R; i++) {
    getline(fin, data.grid.cells[i]);
  }

  data.keyPoints.push_back(data.start);
  for (int r = 0; r < data.grid.R; r++) {
    for (int c = 0; c < data.grid.C; c++) {
      if (data.grid.cells[r][c] == 'c') {
        data.keyPoints.push_back({r, c});
      }
    }
  }
  data.keyPoints.push_back(data.goal);

  return true;
}

string writeOrderAsText(const vector<pair<int, int>>& keyPoints, const vector<int>& order) {
  ostringstream text;
  text << "S";
  for (int i = 0; i < (int)order.size(); i++) {
    int idx = order[i];
    text << " -> c(" << keyPoints[idx].first << "," << keyPoints[idx].second << ")";
  }
  text << " -> G";
  return text.str();
}

int main(int argc, char** argv) {
  string filename = "test_mazes/tiny_2coins.txt";
  if (argc > 1) {
    filename = argv[1];
  }

  MazeData data;
  bool loadedOk = loadMaze(filename, data);
  if (!loadedOk) {
    cout << "hmm, couldn't open the file: " << filename << endl;
    return 1;
  }

  Grid grid = data.grid;
  vector<pair<int, int>> keyPoints = data.keyPoints;
  int startPoint = 0;
  int goalPoint = keyPoints.size() - 1;
  int numCoins = keyPoints.size() - 2;
  int numKeyPoints = keyPoints.size();

  vector<vector<int>> bfsTable(numKeyPoints, vector<int>(numKeyPoints, 0));
  int bfsPairsComputed = 0;
  int bfsTotalExpanded = 0;
  bool bfsOk = true;
  for (int i = 0; i < numKeyPoints; i++) {
    for (int j = i + 1; j < numKeyPoints; j++) {
      Result r = bfs(grid, keyPoints[i], keyPoints[j]);
      if (r.cost == INT_MAX) {
        bfsOk = false;
      }
      bfsTable[i][j] = r.cost;
      bfsTable[j][i] = r.cost;
      bfsTotalExpanded += r.expanded;
      bfsPairsComputed++;
    }
  }

  vector<vector<int>> dijkstraTable(numKeyPoints, vector<int>(numKeyPoints, 0));
  int dijkstraTotalExpanded = 0;
  bool dijkstraOk = true;
  for (int i = 0; i < numKeyPoints; i++) {
    for (int j = i + 1; j < numKeyPoints; j++) {
      Result r = dijkstra(grid, keyPoints[i], keyPoints[j]);
      if (r.cost == INT_MAX) {
        dijkstraOk = false;
      }
      dijkstraTable[i][j] = r.cost;
      dijkstraTable[j][i] = r.cost;
      dijkstraTotalExpanded += r.expanded;
    }
  }

  vector<vector<int>> astarTable(numKeyPoints, vector<int>(numKeyPoints, 0));
  int astarTotalExpanded = 0;
  bool astarOk = true;
  for (int i = 0; i < numKeyPoints; i++) {
    for (int j = i + 1; j < numKeyPoints; j++) {
      Result r = astar(grid, keyPoints[i], keyPoints[j]);
      if (r.cost == INT_MAX) {
        astarOk = false;
      }
      astarTable[i][j] = r.cost;
      astarTable[j][i] = r.cost;
      astarTotalExpanded += r.expanded;
    }
  }

  bool everyoneReachable = bfsOk && dijkstraOk && astarOk;

  cout << "=== UNIFORM COST (BFS + DFS) ===" << endl;
  cout << "Coins: " << numCoins << endl;

  if (!everyoneReachable) {
    cout << "Path found: no" << endl;
    return 0;
  }

  vector<int> uniformOrder;
  int uniformTotal = bestOrder(bfsTable, startPoint, goalPoint, uniformOrder);
  int uniformTried = lastOrderingsTried;
  cout << "Best order: " << writeOrderAsText(keyPoints, uniformOrder) << endl;
  cout << "Total steps: " << uniformTotal << endl;
  cout << "Path:" << endl;

  vector<string> pathGrid = grid.cells;
  vector<int> uniformRoute;
  uniformRoute.push_back(startPoint);
  for (int i = 0; i < (int)uniformOrder.size(); i++) {
    uniformRoute.push_back(uniformOrder[i]);
  }
  uniformRoute.push_back(goalPoint);
  for (int i = 0; i + 1 < (int)uniformRoute.size(); i++) {
    Result legResult = bfs(grid, keyPoints[uniformRoute[i]], keyPoints[uniformRoute[i + 1]]);
    for (int j = 0; j < (int)legResult.path.size(); j++) {
      int pr = legResult.path[j].first;
      int pc = legResult.path[j].second;
      char ch = pathGrid[pr][pc];
      if (ch == '.' || (ch >= '0' && ch <= '9')) {
        pathGrid[pr][pc] = '*';
      }
    }
  }
  for (int i = 0; i < (int)pathGrid.size(); i++) {
    cout << pathGrid[i] << endl;
  }

  cout << endl;
  cout << "=== WEIGHTED (Dijkstra + A*) ===" << endl;
  cout << "Coins: " << numCoins << endl;

  vector<int> weightedOrder;
  int weightedTotal = bestOrder(dijkstraTable, startPoint, goalPoint, weightedOrder);
  int weightedTried = lastOrderingsTried;
  cout << "Best order: " << writeOrderAsText(keyPoints, weightedOrder) << endl;
  cout << "Total cost: " << weightedTotal << endl;
  cout << "A* cells expanded across all pair queries: " << astarTotalExpanded << endl;
  cout << "Dijkstra cells expanded across all pair queries: " << dijkstraTotalExpanded << endl;

  cout << endl;
  cout << "SUMMARY | BFS pairs computed: " << bfsPairsComputed
       << " | DFS orderings tried: " << (uniformTried + weightedTried)
       << " | Dijkstra:" << dijkstraTotalExpanded
       << " | A*:" << astarTotalExpanded << endl;

  return 0;
}

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temp) {
    stack<int> s;
    vector<int> ans((int)temp.size(), 0);
    for (int i = 0; i < (int)temp.size(); i++) {
      while (s.size() && temp[s.top()] < temp[i]) {
        ans[s.top()] = i - s.top();
        s.pop();
      }
      s.push(i);
    }
    return ans;
  }
};
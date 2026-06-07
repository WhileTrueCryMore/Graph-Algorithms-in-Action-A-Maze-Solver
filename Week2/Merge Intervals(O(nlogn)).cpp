class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    int i = 0;
    while (i < intervals.size()) {
      int j = i;
      int st = intervals[i][0];
      int end = intervals[i][1];
      while (j != intervals.size() - 1 && end >= intervals[j + 1][0]) {
        end = max(end, intervals[j + 1][1]);
        j++;
      }
      i = j + 1;
      ans.push_back({st, end});
    }
    return ans;
  }
};
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> final;
    set<int> s(nums.begin(), nums.end());
    vector<int> ans;
    func(s, ans, final);
    return final;
  }

  void func(set<int>& remaining, vector<int>& ans, vector<vector<int>>& final) {
    // final push
    if (remaining.size() == 0) {
      final.push_back(ans);
      return;
    }
    set<int> cur = remaining;
    for (auto x : cur) {
      int r = x;
      ans.push_back(r);
      remaining.erase(r);
      func(remaining, ans, final);
      remaining.insert(r);
      ans.pop_back();
    }
  }
};
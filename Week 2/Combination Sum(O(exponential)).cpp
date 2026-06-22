class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& init, int target) {
    sort(init.begin(), init.end());

    vector<vector<int>> ans;
    vector<int> arr;

    comb(init, target, 0, arr, ans);

    return ans;
  }

  void comb(vector<int>& init, int target, int idx,
            vector<int>& arr, vector<vector<int>>& ans) {
    if (target == 0) {
      ans.push_back(arr);
      return;
    }

    for (int i = idx; i < init.size(); i++) {
      if (init[i] > target)
        break;

      arr.push_back(init[i]);
      comb(init, target - init[i], i, arr, ans);
      arr.pop_back();
    }
  }
};
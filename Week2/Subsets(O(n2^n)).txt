class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> seq;
    for (int i = 0; i < 1 << nums.size(); i++) {
      int k = i;
      vector<int> num;
      for (int j = 0; j < (int)nums.size(); j++) {
        if (k & 1) num.push_back(nums[j]);
        k >>= 1;
      }
      seq.push_back(num);
    }
    return seq;
  }
};
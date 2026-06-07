class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;

    for (int x : nums)
      freq[x]++;

    vector<vector<int>> frequency(nums.size() + 1);

    for (auto [num, cnt] : freq)
      frequency[cnt].push_back(num);

    vector<int> ans;

    for (int f = nums.size(); f >= 1 && ans.size() < k; f--) {
      for (int num : frequency[f]) {
        ans.push_back(num);
        if (ans.size() == k)
          break;
      }
    }

    return ans;
  }
};
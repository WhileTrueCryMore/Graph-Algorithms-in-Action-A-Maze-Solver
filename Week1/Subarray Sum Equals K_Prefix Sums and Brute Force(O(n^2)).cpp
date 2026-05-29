class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pre_sum(n + 1);
    pre_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
    }
    // range_sum(l,r)=pre_sum[r+1]-pre_sum[l+1];
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n + 1; j++) {
        if (pre_sum[j] - pre_sum[i] == k) count++;
      }
    }
    return count;
  }
};
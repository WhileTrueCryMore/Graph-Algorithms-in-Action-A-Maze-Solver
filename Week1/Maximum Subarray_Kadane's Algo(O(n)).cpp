class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int curr = 0;
    int maxm = INT_MIN;
    for (int x : nums) {
      curr += x;
      maxm = max(maxm, curr);
      if (curr < 0) curr = 0;
    }
    return maxm;
  }
};
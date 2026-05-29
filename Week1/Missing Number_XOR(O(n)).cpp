class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int XOR1 = 0;
    for (int i = 1; i <= n; i++) {
      XOR1 ^= i;
    }
    int XOR2 = 0;
    for (int x : nums)
      XOR2 ^= x;
    return XOR1 ^ XOR2;
  }
};
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    vector<int> count(3, 0);
    for (int x : nums) {
      count[x]++;
    }
    int i = 0;
    for (int t = 0; t <= 2; t++) {
      while (count[t]--) {
        nums[i] = t;
        i++;
      }
    }
    return;
  }
};
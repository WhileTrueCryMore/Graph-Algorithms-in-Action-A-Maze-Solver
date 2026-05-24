class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    bool is_last = true;
    int invert = 0;
    for (int j = nums.size() - 1; j >= 1; j--) {
      if (nums[j] > nums[j - 1]) {
        is_last = false;
        invert = j - 1;
        break;
      }
    }
    if (is_last) {
      reverse(nums.begin(), nums.end());
      return;
    }
    for (int j = nums.size() - 1; j > invert; j--) {
      if (nums[j] > nums[invert]) {
        swap(nums[j], nums[invert]);
        break;
      }
    }
    reverse(nums.begin() + invert + 1, nums.end());
    return;
  }
};
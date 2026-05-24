class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      for (int k = i + 1; k < nums.size(); k++)
        if ((nums[i] + nums[k]) == target) {
          vector<int> n{i, k};
          return n;
        }
    }
    return nums;
  }
};
class Solution {
 public:
  int findPos(vector<int>& nums, int target, bool first) {
    int l = 0, r = nums.size() - 1;
    int ans = -1;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (nums[mid] == target) {
        ans = mid;

        if (first)
          r = mid - 1; 
        else
          l = mid + 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return ans;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    return {
        findPos(nums, target, true),
        findPos(nums, target, false)};
  }
};

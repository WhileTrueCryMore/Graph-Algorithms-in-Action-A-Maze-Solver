class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> sorted = nums;

    sort(sorted.begin(), sorted.end());

    int left = 0;
    int right = sorted.size() - 1;

    int firstValue = 0;
    int secondValue = 0;

    while (left < right) {
      int currentSum = sorted[left] + sorted[right];
      if (currentSum == target) {
        firstValue = sorted[left];
        secondValue = sorted[right];
        break;
      } else if (currentSum < target) {
        left++;
      } else {
        right--;
      }
    }

    int firstIndex = -1;
    int secondIndex = -1;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == firstValue && firstIndex == -1) {
        firstIndex = i;
      } else if (nums[i] == secondValue && secondIndex == -1) {
        secondIndex = i;
      }
    }

    return {firstIndex, secondIndex};
  }
};
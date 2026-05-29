class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;
    vector<int> left_max(n);
    vector<int> right_max(n);
    int leftmax = 0;
    int rightmax = 0;
    int vol = 0;
    for (int i = 0; i < n; i++) {
      if (height[i] > leftmax) {
        leftmax = height[i];
      }
      left_max[i] = leftmax;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (height[i] > rightmax) {
        rightmax = height[i];
      }
      right_max[i] = rightmax;
    }
    for (int i = 0; i < n; i++) {
      vol += min(left_max[i], right_max[i]) - height[i];
    }
    return vol;
  }
};
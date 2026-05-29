class Solution {
 public:
  int maxArea(vector<int>& height) {
    int start = 0;
    int end = height.size() - 1;
    long long max_vol = 0;
    while (start < end) {
      long long vol = min(height[start], height[end]) * (end - start);
      max_vol = max(max_vol, vol);
      if (height[start] < height[end]) {
        start++;
      } else
        end--;
    }
    return max_vol;
  }
};
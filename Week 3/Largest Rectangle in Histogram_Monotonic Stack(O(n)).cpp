class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> right_smaller;
    vector<int> right_extension(n);
    vector<int> left_extension(n);
    stack<int> left_smaller;
    for (int i = 0; i < n; i++) {
      while (!right_smaller.empty() &&
             heights[right_smaller.top()] > heights[i]) {
        right_extension[right_smaller.top()] = i - right_smaller.top();
        right_smaller.pop();
      }
      right_smaller.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
      while (!left_smaller.empty() &&
             heights[left_smaller.top()] > heights[i]) {
        left_extension[left_smaller.top()] = left_smaller.top() - i;
        left_smaller.pop();
      }
      left_smaller.push(i);
    }
    while (!right_smaller.empty()) {
      right_extension[right_smaller.top()] = n - right_smaller.top();
      right_smaller.pop();
    }
    while (!left_smaller.empty()) {
      left_extension[left_smaller.top()] = left_smaller.top() + 1;
      left_smaller.pop();
    }
    int ar_max = 0;
    for (int i = 0; i < n; i++) {
      int ar = (left_extension[i] + right_extension[i] - 1) * heights[i];
      ar_max = max(ar, ar_max);
    }
    return ar_max;
  }
};
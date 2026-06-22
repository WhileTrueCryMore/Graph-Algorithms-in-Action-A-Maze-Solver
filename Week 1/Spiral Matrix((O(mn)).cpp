class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int count = 0;
    vector<int> spir;
    int top = 0, left = 0, right = n - 1, bottom = m - 1;
    while (top <= bottom && left <= right) {
      for (int i = left; i <= right; i++) {
        spir.push_back(matrix[top][i]);
        count++;
      }
      top++;
      if (count == m * n) break;
      for (int i = top; i <= bottom; i++) {
        spir.push_back(matrix[i][right]);
        count++;
      }
      right--;
      if (count == m * n) break;
      for (int i = right; i >= left; i--) {
        spir.push_back(matrix[bottom][i]);
        count++;
      }
      bottom--;
      if (count == m * n) break;
      for (int i = bottom; i >= top; i--) {
        spir.push_back(matrix[i][left]);
        count++;
      }
      left++;
      if (count == m * n) break;
    }
    return spir;
  }
};
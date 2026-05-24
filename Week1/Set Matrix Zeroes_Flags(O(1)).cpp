class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool row_0 = false;
    bool col_0 = false;
    for (int i = 0; i < cols; i++) {
      if (matrix[0][i] == 0) {
        row_0 = true;
        break;
      }
    }
    for (int i = 0; i < rows; i++) {
      if (matrix[i][0] == 0) {
        col_0 = true;
        break;
      }
    }
    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (row_0) {
      for (int i = 0; i < cols; i++)
        matrix[0][i] = 0;
    }
    if (col_0) {
      for (int i = 0; i < rows; i++)
        matrix[i][0] = 0;
    }
  }
};
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal(numRows);
    for (auto& x : pascal) {
      x.push_back(1);
    };
    if (numRows > 1)
      pascal[1].push_back(1);
    for (int i = 2; i < numRows; i++) {
      int index = 1;
      while (index < i) {
        pascal[i].push_back(pascal[i - 1][index - 1] +
                            pascal[i - 1][index]);
        index++;
      }
      pascal[i].push_back(1);
    }
    return pascal;
  }
};
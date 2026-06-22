class Solution {
 public:
  void moveZeroes(vector<int>& v) {
    int j = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] != 0) {
        if (i != j)
          swap(v[i], v[j]);
        j++;
      }
    }
  }
};
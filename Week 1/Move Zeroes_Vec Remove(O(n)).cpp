class Solution {
 public:
  void moveZeroes(vector<int>& v) {
    int trailing = 0;

    for (int i = v.size() - 1; i >= 0 && v[i] == 0; i--)
      trailing++;

    auto newEnd = remove(v.begin(), v.end() - trailing, 0) - v.begin();

    for (int i = newEnd; i < v.size() - trailing; i++)
      v[i] = 0;
  }
};
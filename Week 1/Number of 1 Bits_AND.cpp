class Solution {
 public:
  int hammingWeight(int n) {
    short int count = 0;
    while (n != 0) {
      if (n & 1) count++;
      n >>= 1;
    }
    return count;
  }
};
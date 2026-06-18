class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());

    int mx = 0;

    for (int x : st) {
      if (!st.count(x - 1)) {
        int len = 1;
        int cur = x;

        while (st.count(cur + 1)) {
          cur++;
          len++;
        }

        mx = max(mx, len);
      }
    }
    return mx;
  }
};
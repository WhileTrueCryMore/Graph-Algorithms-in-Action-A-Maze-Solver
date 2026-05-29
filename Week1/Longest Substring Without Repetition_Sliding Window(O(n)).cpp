class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();

    vector<int> freq(256, 0);
    int l = 0;
    int maxm = 0;
    for (int r = 0; r < n; r++) {
      freq[s[r]]++;
      maxm;
      while (freq[s[r]] > 1) {
        freq[s[l]]--;
        l++;
      }
      maxm = max(maxm, r - l + 1);
    }
    return maxm;
  }
};
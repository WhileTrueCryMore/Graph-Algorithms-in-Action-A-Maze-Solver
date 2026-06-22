class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;

    vector<int> frequency(26, 0);

    for (char c : s)
      frequency[c - 'a']++;

    for (char c : t) {
      if (frequency[c - 'a'] == 0) return false;
      frequency[c - 'a']--;
    }

    return true;
  }
};
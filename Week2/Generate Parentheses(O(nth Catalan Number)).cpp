class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    string ans;
    ans.reserve(2 * n);
    vector<string> final;
    genpar(final, ans, 0, 0, n);
    return final;
  }
  void genpar(vector<string>& final, string& ans, int leftpar, int rightpar, int target) {
    if (leftpar == rightpar && leftpar == target) {
      final.push_back(ans);
      return;
    }

    if (leftpar < target) {
      ans.push_back('(');
      genpar(final, ans, leftpar + 1, rightpar, target);
      ans.pop_back();
    }

    if (rightpar < leftpar) {
      ans.push_back(')');
      genpar(final, ans, leftpar, rightpar + 1, target);
      ans.pop_back();
    }
  }
};
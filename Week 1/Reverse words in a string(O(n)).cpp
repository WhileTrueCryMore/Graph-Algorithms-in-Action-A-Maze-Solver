class Solution {
 public:
  string reverseWords(string s) {
    vector<string> arr;
    string word;

    for (char c : s) {
      if (c != ' ') {
        word.push_back(c);
      } else if (word != "") {
        arr.push_back(word);
        word.clear();
      }
    }

    if (word != "") {
      arr.push_back(word);
    }

    string ans;

    for (int i = arr.size() - 1; i >= 0; i--) {
      ans += arr[i];

      if (i != 0) {
        ans += " ";
      }
    }

    return ans;
  }
};
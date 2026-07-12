class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());

    if (!words.count(endWord))
      return 0;

    int len = beginWord.size();

    queue<string> q;
    q.push(beginWord);
    words.erase(beginWord);

    int level = 1;

    while (!q.empty()) {
      int sz = q.size();

      for (int i = 0; i < sz; i++) {
        string word = q.front();
        q.pop();

        if (word == endWord)
          return level;

        for (int j = 0; j < len; j++) {
          char original = word[j];

          for (char c = 'a'; c <= 'z'; c++) {
            if (c == original)
              continue;

            word[j] = c;

            if (words.count(word)) {
              q.push(word);
              words.erase(word);
            }
          }

          word[j] = original;
        }
      }

      level++;
    }

    return 0;
  }
};
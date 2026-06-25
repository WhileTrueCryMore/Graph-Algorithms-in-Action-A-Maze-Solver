class Trie {
 public:
  struct Node {
    Node* child[26];
    bool end;

    Node() {
      end = false;
      for (int i = 0; i < 26; i++)
        child[i] = nullptr;
    }
  };

  Node* root;

  Trie() { root = new Node(); }

  void insert(string word) {
    Node* curr = root;

    for (char c : word) {
      int idx = c - 'a';

      if (curr->child[idx] == nullptr)
        curr->child[idx] = new Node();

      curr = curr->child[idx];
    }

    curr->end = true;
  }

  bool search(string word) {
    Node* curr = root;

    for (char c : word) {
      int idx = c - 'a';

      if (curr->child[idx] == nullptr)
        return false;

      curr = curr->child[idx];
    }

    return curr->end;
  }

  bool startsWith(string prefix) {
    Node* curr = root;

    for (char c : prefix) {
      int idx = c - 'a';

      if (curr->child[idx] == nullptr)
        return false;

      curr = curr->child[idx];
    }

    return true;
  }
};
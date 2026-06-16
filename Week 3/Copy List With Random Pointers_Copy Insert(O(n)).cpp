class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    Node* cur = head;
    while (cur) {
      Node* copy = new Node(cur->val);
      copy->next = cur->next;
      cur->next = copy;
      cur = copy->next;
    }

    cur = head;
    while (cur) {
      if (cur->random)
        cur->next->random = cur->random->next;
      cur = cur->next->next;
    }

    Node* dummy = new Node(0);
    Node* tail = dummy;

    cur = head;
    while (cur) {
      Node* copy = cur->next;

      cur->next = copy->next;

      tail->next = copy;
      tail = copy;

      cur = cur->next;
    }

    return dummy->next;
  }
};
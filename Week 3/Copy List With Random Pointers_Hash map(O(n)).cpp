class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return NULL;
    }
    unordered_map<Node*, Node*> mp;
    Node* head2 = new Node(head->val);
    mp[head] = head2;
    Node* temp1 = head->next;
    Node* temp2 = head2;
    while (temp1) {
      Node* prev = temp2;
      temp2 = new Node(temp1->val);
      mp[temp1] = temp2;
      prev->next = temp2;
      temp1 = temp1->next;
    }
    Node* a1 = head;
    Node* a2 = head2;
    while (a1) {
      a2->random = mp[a1->random];
      a1 = a1->next;
      a2 = a2->next;
    }
    return head2;
  }
};
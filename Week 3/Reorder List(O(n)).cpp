/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    // Find middle
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Reverse second half
    ListNode *prev = nullptr, *cur = slow->next;
    slow->next = nullptr;

    while (cur) {
      ListNode* nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }

    // Merge
    ListNode *l1 = head, *l2 = prev;

    while (l2) {
      ListNode* nxt1 = l1->next;
      ListNode* nxt2 = l2->next;

      l1->next = l2;
      l2->next = nxt1;

      l1 = nxt1;
      l2 = nxt2;
    }
  }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Phase 1: detect if cycle exists
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        // Phase 2: find cycle start
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        if (slow == fast)
          return slow;  // cycle start node
      }
    }

    return nullptr;  // no cycle
  }
};
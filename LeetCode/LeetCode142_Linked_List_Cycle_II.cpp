/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;

      if (slow == fast) {
        auto ptr = head;
        while (ptr != slow) {
          ptr = ptr->next;
          slow = slow->next;
        }
        return ptr;
      }
    }
    return nullptr;
  }
};
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
  bool hasCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) return true;
    }
    return false;
  }
};
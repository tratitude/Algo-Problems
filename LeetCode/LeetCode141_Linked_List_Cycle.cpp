// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
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
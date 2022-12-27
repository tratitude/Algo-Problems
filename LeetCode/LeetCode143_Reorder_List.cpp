/*
1. stack
- Time complexity: O(N)
- Space complexity: O(N)

2. reverse and merge
- Time complexity: O(N)
- Space complexity: O(1)
*/
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  void reorderList(ListNode* head) {
    ListNode *head1 = head, *midNode = findMid(head);
    ListNode* head2 = midNode->next;
    midNode->next = nullptr;

    head2 = reverseList(head2);
    mergeList(head1, head2);
  }
  ListNode* findMid(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
  ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *cur = head, *next = nullptr;
    while (cur != nullptr) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
  void mergeList(ListNode* head1, ListNode* head2) {
    ListNode *ptr1 = head1, *ptr2 = head2;
    while (ptr2 != nullptr) {
      ListNode *next1 = ptr1->next, *next2 = ptr2->next;
      ptr1->next = ptr2;
      ptr2->next = next1;
      ptr1 = next1;
      ptr2 = next2;
    }
  }
};
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
// stack approach
// Time complexity: O(N)
// Space complexity: O(N)
/*
class Solution {
  int N = 0;

 public:
  ListNode* helper(ListNode* head) {
    if (head == nullptr) return nullptr;

    head->next = helper(head->next);

    if (--N == 0)
      return head->next;
    else
      return head;
  }
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    N = n;
    return helper(head);
  }
};
*/
// length approach
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *p = head, *q = head;

    while (n--) p = p->next;
    // remove first element
    if (p == nullptr) return head->next;

    while (p->next != nullptr) {
      p = p->next;
      q = q->next;
    }
    // remove n'th element
    q->next = q->next->next;

    return head;
  }
};
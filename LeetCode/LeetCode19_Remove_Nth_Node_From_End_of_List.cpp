// Time complexity: O(N)
// Space complexity: O(1)
// N: length of list
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, *slow = head;

    while (n--) fast = fast->next;

    // remove first element
    if (fast == nullptr) return head->next;

    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
  }
};
// length approach
// Time complexity: O(N)
// Space complexity: O(1)
// N: length of list
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    auto ptr = head;
    while (ptr != nullptr) {
      ptr = ptr->next;
      ++len;
    }
    if (len == n) return head->next;
    ptr = head;
    for (int i = 0; i < len - n - 1; i++) {
      ptr = ptr->next;
    }
    ptr->next = ptr->next->next;

    return head;
  }
};

// length approach
// Time complexity: O(N)
// Space complexity: O(1)
// N: length of list
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

// stack approach
// Time complexity: O(N)
// Space complexity: O(N)
// N: length of list
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

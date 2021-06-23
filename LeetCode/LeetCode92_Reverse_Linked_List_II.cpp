// Time complexity: O(N)
// Space complexity: O(1)
// N: length of list
class Solution {
 public:
  ListNode* reverse(ListNode* begin, ListNode* end) {
    auto prev = end, cur = begin, next = begin;
    while (cur != end) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    auto ptr = head, begin = head, end = head;
    for (int i = 1; i <= right; i++) {
      if (i == left - 1) {
        begin = ptr;
      }
      ptr = ptr->next;
    }
    end = ptr;
    if (left == 1) {
      head = reverse(begin, end);
    } else {
      begin->next = reverse(begin->next, end);
    }

    return head;
  }
};
// Time complexity: O(N)
// Space complexity: O(N)
// N: length of list
class Solution {
 public:
  // reverse a list from the first to right
  ListNode* reverse(ListNode* head, int right) {
    static ListNode* rightNextPtr{nullptr};
    if (right == 1) {
      rightNextPtr = head->next;
      return head;
    }
    ListNode* last = reverse(head->next, --right);
    head->next->next = head;
    head->next = rightNextPtr;
    return last;
  }

  // reverse a list from left to right
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == 1) {
      return reverse(head, right);
    }
    head->next = reverseBetween(head->next, left - 1, right - 1);
    return head;
  }
};
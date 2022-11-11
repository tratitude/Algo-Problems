// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* prev = nullptr, *cur = head, *next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        auto lastNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return lastNode;
    }
};
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
  ListNode* prev = nullptr;

 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return prev;

    ListNode* next = head->next;
    head->next = prev;
    prev = head;

    return reverseList(next);
  }
};

// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *next = nullptr;

    while (head != nullptr) {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    return prev;
  }
};
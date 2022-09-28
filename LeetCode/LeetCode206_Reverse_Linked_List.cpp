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
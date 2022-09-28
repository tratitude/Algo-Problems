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
  int len = 0;

 public:
  ListNode* middleNode(ListNode* head) {
    if (head == nullptr) return head;

    int cur_len = ++len;
    ListNode* node = middleNode(head->next);
    if (cur_len == ceil((len - 1) / 2.0) + 1) return head;
    return node;
  }
};

// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    int len = 0;
    ListNode *ans = nullptr, *ptr = head;

    while (ptr != nullptr) {
      ++len;
      ptr = ptr->next;
    }
    ptr = head;
    for (int i = 0; i < len; i++) {
      if (i == ceil((len - 1) / 2.0)) {
        ans = ptr;
        break;
      }
      ptr = ptr->next;
    }

    return ans;
  }
};
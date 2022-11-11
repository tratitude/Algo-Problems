// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
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
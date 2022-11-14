// Time complexity: O(N+M)
// Space complexity: O(1)
// N: node numbers of l1
// M: node numbers of l2
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (length(l1) < length(l2)) swap(l1, l2);
    int carray = 0;
    ListNode *head = l1, *prev = nullptr;

    while (l1) {
      int sum = carray + l1->val + (l2 != nullptr ? l2->val : 0);
      l1->val = sum % 10;
      carray = sum / 10;
      prev = l1;
      l1 = l1->next;
      l2 = l2 != nullptr ? l2->next : l2;
      if (l2 == nullptr && carray == 0) break;
    }
    if (carray > 0) prev->next = new ListNode(carray);
    return head;
  }
  int length(ListNode* head) {
    int len = 0;
    while (head) {
      ++len;
      head = head->next;
    }
    return len;
  }
};
// Time complexity: O(N)
// Space complexity: O(1)
// N: max node numbers of l1 and l2
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto ans = l1;
    auto prev = l1;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry > 0) {
      if (l1 == nullptr) {
        l1 = new ListNode;
        prev->next = l1;
      }
      int num1 = l1->val;
      int num2 = l2 == nullptr ? 0 : l2->val;

      l1->val = (num1 + num2 + carry) % 10;
      carry = (num1 + num2 + carry) / 10;

      // update prev
      prev = l1;

      l1 = l1->next;
      if (l2 != nullptr) {
        l2 = l2->next;
      }
    }
    return ans;
  }
};

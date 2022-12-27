// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return head;

    int size = listSize(head);
    k %= size;
    if (k == 0) return head;

    ListNode* end1 = findNode(head, size - k - 1);
    ListNode *head1 = head, *head2 = end1->next;
    end1->next = nullptr;
    concatList(head2, head1);
    return head2;
  }

  int listSize(ListNode* head) {
    int size = 0;
    while (head != nullptr) {
      head = head->next;
      ++size;
    }
    return size;
  }
  // 0-indiced
  ListNode* findNode(ListNode* head, int k) {
    while (k--) {
      head = head->next;
    }
    return head;
  }
  ListNode* concatList(ListNode* lhs, ListNode* rhs) {
    ListNode* endLhs = findNode(lhs, listSize(lhs) - 1);
    endLhs->next = rhs;
    return lhs;
  }
};
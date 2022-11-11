// Time complexity: O(N+M)
// Space complexity: O(N+M)
// N: number of nodes in list1
// M: number of nodes in list2
/*
list = min(list1, list2)
list->next = mergeTwoLists(list1, list2)
// base case
list->next = nullptr if (list1 == list2 == nullptr)
list->next = list1 if (list2 == nullptr)
list->next = list2 if (list1 == nullptr)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        ListNode* node = new ListNode(min(list1->val, list2->val));
        if (node->val == list1->val) {
            node->next = mergeTwoLists(list1->next, list2);
        } else {
            node->next = mergeTwoLists(list1, list2->next);
        }
        return node;
    }
};
// Time complexity: O(N+M)
// Space complexity: O(1)
// N: number of nodes in list1
// M: number of nodes in list2
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1);
    ListNode* cur = head;

    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val <= l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }

    if (l1 != nullptr)
      cur->next = l1;
    else if (l2 != nullptr)
      cur->next = l2;

    return head->next;
  }
};
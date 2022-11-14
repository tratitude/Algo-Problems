// Time complexity: O(N)
// Space complexity: O(N)
/*
// assum number of nodes > 0
fun swap(p, q)
    if q == nullptr return p

    if (q->next != nullptr)
        q->next = swap(q->next, q->next->next)

    next = q->next
    q->next = p
    p->next = next
    return q
*/
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) return head;
    return mySwap(head, head->next);
  }
  ListNode* mySwap(ListNode* p, ListNode* q) {
    if (q == nullptr) return p;

    if (q->next != nullptr) q->next = mySwap(q->next, q->next->next);
    auto next = q->next;
    q->next = p;
    p->next = next;
    return q;
  }
};
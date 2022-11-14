// Time complexity: O(N)
// Space complexity: O(1)
/*
[1,2,3,4,5,6]
 o e      nextOdd = e->next, nextEven = e->next->next
          o->next = nextOdd, nextOdd->next = firstEven, o = nextOdd
          e->next = nextEven, e = nextEven
[1,3,2,4,5,6]
   o   e
[1,3,5,2,4,6]
     o     e  if (e->next == nullptr) return head
[1,2,3]
 o e     nextOdd = e->next, nextEven = e->next->next
         o->next = nextOdd, nextOdd->next = firstEven, o = nextOdd
         e->next = nextEven, e = nextEven
[1,3,2]
   o   e  if (e == nullptr) return head
[1,2]
[1]
[]
*/
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode *odd = head, *even = head->next, *firstEven = head->next;

    while (even != nullptr && even->next != nullptr) {
      ListNode *nextOdd = even->next, *nextEven = even->next->next;

      odd->next = nextOdd;
      nextOdd->next = firstEven;
      odd = nextOdd;
      even->next = nextEven;
      even = nextEven;
    }
    return head;
  }
};
// Time complexity: O(N)
// Space complexity: O(1)
/*
// change the direction of list [0, len/2], except fast == nullptr
// slow stop at len/2, if fast == nullptr -> l1 = prev, l2 = slow
//                     else               -> l1 = slow, l2 = slow
while (fast != nullptr && fast->next != nullptr)

// compare l1 and l2

*/
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    ListNode *prev = nullptr, *slow = head, *next = nullptr, *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }
    ListNode* l1 = prev;
    ListNode* l2 = fast == nullptr ? slow : slow->next;
    while (l2 != nullptr) {
      if (l2->val != l1->val) return false;
      l2 = l2->next;
      l1 = l1->next;
    }
    return true;
  }
};
#include <iostream>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printList(ListNode* head){
    ListNode* ptr = head;
    while(ptr){
        cout << ptr->val << "\n";
        ptr = ptr->next;
    }
}

void createList(ListNode* head, list<int> &v){
    head->val = v.front();
    v.pop_front();
    ListNode* ptr = head;
    for(auto i : v){
        ptr->next = new ListNode;
        ptr = ptr->next;
        ptr->val = i;
    }
}

ListNode* reverse(ListNode* head){
    ListNode *pre{nullptr}, *cur{head}, *nxt{head};
    while(cur!=nullptr){
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

bool isPalindrome_reverse(ListNode* head) {
    ListNode *fast{head}, *slow{head}, *reverseHead{nullptr};
    while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast != nullptr){
        slow = slow->next;
    }
    reverseHead = reverse(slow);
    while(reverseHead != nullptr){
        if(reverseHead->val != head->val) return false;
        reverseHead = reverseHead->next;
        head = head->next;
    }
    return true;
}

ListNode *front{nullptr};

bool traverse(ListNode* head) {
    if(head == nullptr) return true;
    bool ans = traverse(head->next);
    ans = ans && (front->val == head->val);
    front = front->next;
    return ans;
}

bool isPalindrome(ListNode* head) {
    front = head;
    return traverse(head);
}

int main(){
    list<int> v{1,2};
    ListNode* head = new ListNode;
    createList(head, v);
    printList(head);

    cout << isPalindrome(head);
}
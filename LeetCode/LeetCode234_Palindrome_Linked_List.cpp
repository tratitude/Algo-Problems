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
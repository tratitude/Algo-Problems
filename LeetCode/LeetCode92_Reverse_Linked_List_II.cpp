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
 
ListNode* reverse(ListNode* head) {
    if (head->next == nullptr) return head;
    ListNode* last = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}

// reverse a list from the first to right
ListNode* reverse(ListNode* head, int right){
    static ListNode* rightNextPtr{nullptr};
    if(right==1){
        rightNextPtr = head->next;
        return head;
    }
    ListNode* last = reverse(head->next, --right);
    head->next->next = head;
    head->next = rightNextPtr;
    return last;
}

// reverse a list from left to right
ListNode* reverseBetween(ListNode* head, int left, int right){
    if(left == 1){
        return reverse(head, right);
    }
    head->next = reverseBetween(head->next, left-1, right-1);
    return head;
}

// reverse a list from left to right
// WA in this case: {3} = revers(head{3, 5}, 1, 2)
ListNode* reverse(ListNode* head, int left, int right){
    static int counter{1};
    static ListNode *rightNextPtr{nullptr}, *rightPtr{nullptr};
    if(counter==right){
        rightNextPtr = head->next;
        rightPtr = head;
        return head;
    }
    else{
        ++counter;
    }
    reverse(head->next, left, right);
    --counter;
    if(counter>=left){
        head->next->next = head;
        head->next = rightNextPtr;
    }
    else if(left>1 && counter==left-1){
        head->next = rightPtr;
    }
    return head;
}

int main(){
    list<int> v{1,2,3,4,5,6};
    ListNode* head = new ListNode;
    createList(head, v);
    printList(head);

    //head = reverse(head);

    //printList(head);

    //head = reverse(head, 3);

    //printList(head);

    //head = reverseBetween(head, 2, 4);

    //printList(head);

    head = reverse(head, 2, 4);

    printList(head);
}
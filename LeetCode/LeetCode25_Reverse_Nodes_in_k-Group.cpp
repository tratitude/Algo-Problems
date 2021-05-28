#include <iostream>
#include <list>
#include <stack>

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

ListNode* reverse(ListNode* head, ListNode *right){
    ListNode *pre{nullptr}, *cur{head}, *nxt{head};
    while(cur != right){
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

ListNode* reverseKGroup_recursive(ListNode* head, int k) {
    ListNode *right{head};
    for(auto i{0}; i<k; ++i){
        if(!right) return head;
        right = right->next;
    }
    ListNode *newHead = reverse(head, right);
    head->next = reverseKGroup_recursive(right, k);
    return newHead;
}

void pushListNode(ListNode **head, int val){
    static bool firstInset{true};
    if(firstInset){
        firstInset = false;
    }
    else{
        (*head)->next = new ListNode;
        (*head) = (*head)->next;
    }
    (*head)->val = val;
}

// bad memory usage
// WA on leetcode judge but passed on my laptop
// {0,3,2,1,4,5} = reverseKGroup_stack({1,2,3,4,5}, 3)
ListNode* reverseKGroup_stack(ListNode* head, int k) {
    ListNode *reverseHead = new ListNode;
    ListNode *ptr = reverseHead;
    stack<int> reverseStack;
    while(head){
        // check list is still bigger than k, set flag lessK
        bool lessK = false;
        auto checkPtr{head};
        for(auto i{0}; i<k; ++i){
            if(!checkPtr){
                lessK = true;
                break;
            }
            checkPtr = checkPtr->next;
        }
        if(lessK){
            while(head){
                pushListNode(&ptr, head->val);
                head = head->next;
            }
        }
        else{
            for(auto i{0}; i<k; ++i){
                reverseStack.push(head->val);
                head = head->next;
            }
            for(auto i{0}; i<k; ++i){
                pushListNode(&ptr, reverseStack.top());
                reverseStack.pop();
            }
        }
    }
    return reverseHead;
}

// lazy to implement
ListNode* reverseKGroup_iteration(ListNode* head, int k) {
    int listLen{0};
    for(auto ptr{head}; ptr != nullptr; ptr = ptr->next){
        ++listLen;
    }

}

int main(){
    list<int> v{1,2,3,4,5};
    ListNode* head = new ListNode;
    createList(head, v);
    //printList(head);

    head = reverseKGroup_stack(head, 3);

    printList(head);
}
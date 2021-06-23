// Time complexity: O(N)
// Space complexity: O(N)
// N: length of list head
class Solution {
 public:
  // input head will reverse to end
  // output the head
  void reverse(ListNode* front, ListNode* end) {
    ListNode *prev = nullptr, *cur = front, *next = front;

    while (prev != end) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    stack<pair<ListNode*, ListNode*>> st;
    int count = k;
    auto end = head;
    auto front = head;

    while (end != nullptr) {
      --count;
      if (count == k - 1) {
        front = end;
      } else if (count == 0) {
        st.push({front, end});
        count = k;
      }

      end = end->next;
    }

    ListNode* prevFront = count != k ? front : nullptr;
    while (!st.empty()) {
      auto [front, end] = st.top();
      st.pop();
      reverse(front, end);
      front->next = prevFront;
      prevFront = end;
    }

    return prevFront;
  }
};

// Time complexity: O(N)
// Space complexity: O(N)
// N: length of list head
class Solution {
 public:
  ListNode* reverse(ListNode* head, ListNode* right) {
    ListNode *pre{nullptr}, *cur{head}, *nxt{head};
    while (cur != right) {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    return pre;
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* right{head};
    for (auto i{0}; i < k; ++i) {
      if (!right) return head;
      right = right->next;
    }
    ListNode* newHead = reverse(head, right);
    head->next = reverseKGroup(right, k);
    return newHead;
  }
};
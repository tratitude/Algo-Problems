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

// Sliding window
// Time complexity: O(N)
// Space complexity: O(n)
// N: max node numbers of l1 and l2
int lengthOfLongestSubstring(string s) {
  int l = 0, r = 0, res = 0;
  unordered_map<char, int> m;
  while (r < s.size()) {
    ++m[s[r]];
    if (m[s[r]] > 1) {
      while (m[s[r]] > 1) {
        --m[s[l++]];
      }
      res = res > (r - l + 1) ? res : r - l + 1;
    } else
      res = res > (r - l + 1) ? res : r - l + 1;
    ++r;
  }
  return res;
}

// Brute force
// Time complexity: O(N^2)
// Space complexity: O(N)
// N: max node numbers of l1 and l2
int lengthOfLongestSubstring(string s) {
  if (s.size() == 1) return 1;
  int maxLen = 0;
  for (int i = 0; i < s.size(); ++i) {
    int len = 1;
    set<int> alphabet;
    alphabet.insert(s[i]);
    for (int j = i + 1; j < s.size(); ++j) {
      auto it = alphabet.find(s[j]);
      if (it != alphabet.end()) {
        maxLen = maxLen > len ? maxLen : len;
        break;
      }
      ++len;
      maxLen = maxLen > len ? maxLen : len;
      alphabet.insert(s[j]);
    }
  }
  return maxLen;
}
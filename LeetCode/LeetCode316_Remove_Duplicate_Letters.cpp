// Time complexity: O(N)
// Space complexity: O(N)
// N: length of s
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    vector<int> feq(256, 0);
    vector<bool> seen(256, false);
    stack<int> st;

    // init feq
    for (char c : s) ++feq[c];

    for (char c : s) {
      --feq[c];
      if (seen[c]) continue;
      // keep the small one at the bottom
      while (!st.empty() and st.top() > c and feq[st.top()]) {
        seen[st.top()] = false;
        st.pop();
      }
      st.push(c);
      seen[c] = true;
    }

    string res;
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    reverse(res.begin(), res.end());

    return res;
  }
};
// Time complexity: O(4^N / sqrt(N))
// Space complexity: O(4^N / sqrt(N))
// N: n
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    if (n == 0) {
      ans.push_back("");
    } else {
      for (int i = 0; i < n; i++) {
        for (auto& left : generateParenthesis(i)) {
          for (auto& right : generateParenthesis(n - 1 - i)) {
            string s = "(" + left + ")" + right;
            ans.push_back(s);
          }
        }
      }
    }
    return ans;
  }
};

// Time complexity: O(4^N / sqrt(N))
// Space complexity: O(4^N / sqrt(N))
// N: n
class Solution {
  int L, R;
  vector<string> Res;
  string S;

 public:
  void bruteforce(int idx) {
    if (!idx) {
      Res.push_back(S);
      return;
    }

    if (L > 0) {
      --L;
      S.push_back('(');
      bruteforce(idx - 1);
      ++L;
      S.pop_back();
    }
    if (R > 0 and R > L) {
      --R;
      S.push_back(')');
      bruteforce(idx - 1);
      ++R;
      S.pop_back();
    }
  }
  vector<string> generateParenthesis(int n) {
    L = n, R = n;
    bruteforce(n * 2);
    return Res;
  }
};
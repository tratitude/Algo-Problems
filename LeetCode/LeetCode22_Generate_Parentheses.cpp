// Time complexity: O(N!)
// Space complexity: O(N)
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
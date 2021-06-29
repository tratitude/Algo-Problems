// Time complexity: O(N)
// Space complexity: O(N)
// N: size of b
class Solution {
  const int Mod = 1337;

 public:
  int fastPow(int a, int b) {
    if (b == 0) return 1;
    // a*a^(b-1)
    // (a^(b/2))^2
    int ans = 0;
    a %= Mod;
    if (b & 1) {
      ans = (a * fastPow(a, b - 1)) % Mod;
    } else {
      ans = fastPow(a, b / 2);
      ans = (ans * ans) % Mod;
    }
    return ans;
  }
  int superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;
    int last = b.back();
    b.pop_back();

    int num1 = fastPow(a, last);
    int num2 = fastPow(superPow(a, b), 10);

    return (num1 * num2) % Mod;
  }
};
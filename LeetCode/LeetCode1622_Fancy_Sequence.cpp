// Approach: Cache the ops, update the value when getIndex() is called.
// seq[]:     1   2   3   4   5
// cache[][]: +1  *2  *2  +3  *4
//            *2  +3  +3  *4
//            +3  *4  *4
//            *4
// cache can be deduced by linear form y = ax + b
// Time complexity:
//   addAll(), multAll(): O(N), N is the number of seq. Can be optimized to
//   O(log(N)) by segment tree.
//   getIndex(): O(1)
// Space complexity: O(N)
// Status: TLE
class Fancy {
  using LL = long long;
  // first = a, second = b
  using pll = pair<LL, LL>;
  const int kMod = 1e9 + 7;
  vector<pll> ops;
  vector<int> seq;

 public:
  Fancy() {}

  void append(int val) {
    seq.emplace_back(val);
    ops.emplace_back(1, 0);
  }

  void addAll(int inc) {
    for (auto& [a, b] : ops) {
      b = (b + inc) % kMod;
    }
  }

  void multAll(int m) {
    for (auto& [a, b] : ops) {
      a = (a * m) % kMod;
      b = (b * m) % kMod;
    }
  }

  int getIndex(int idx) {
    if (idx >= seq.size()) return -1;
    LL ans = ops[idx].first * seq[idx] + ops[idx].second;
    return ans % kMod;
  }
};

// Approach: Build a segment tree with leaner form dynamicly when addAll() or
// multAll() is called. Calculate the result with segment tree in [idx, seq.size]
// when getIndex(idx) is called.
// Time complexity: O(log(N))
// Space complecity: O(N)
// Approach: Trie
// Time complexity: O(N)
// Space complexity: O(M)
// N: number of pairs
// M: sum of all keys' length
class MapSum {
  struct Node {
    Node(int sum = 0) : sum(sum) {}
    unordered_map<char, Node *> next;
    int sum;
  };
  Node root;
  unordered_map<string, int> memo;

  int InsertVal(const string &key, int val) {
    if (!memo.count(key)) {
      memo[key] = val;
      return val;
    }
    int diff = val - memo[key];
    memo[key] = val;

    return diff;
  }

 public:
  /** Initialize your data structure here. */
  MapSum() {}

  void insert(string key, int val) {
    Node *ptr = &root;
    val = InsertVal(key, val);
    for (auto c : key) {
      if (!ptr->next.count(c)) {
        ptr->next[c] = new Node;
      }
      ptr = ptr->next[c];
      ptr->sum += val;
    }
  }

  int sum(string prefix) {
    Node *ptr = &root;
    for (auto c : prefix) {
      if (!ptr->next.count(c)) {
        return 0;
      }
      ptr = ptr->next[c];
    }
    return ptr->sum;
  }
};
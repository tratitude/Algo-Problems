// Time complexity: O(n)
// Space complexity: O(1)
// n: number of equations
class Solution {
 public:
  class UF {
    int count;
    int* parent;
    int* size;

   public:
    UF(int n) : count(n) {
      parent = new int[n];
      size = new int[n];

      for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
      }
    }
    void unionf(int p, int q) {
      int pRoot = find(p);
      int qRoot = find(q);

      if (pRoot == qRoot) return;

      // small union connect to big union
      if (size[pRoot] < size[qRoot]) {
        parent[pRoot] = qRoot;
        size[qRoot] += size[pRoot];
      } else {
        parent[qRoot] = pRoot;
        size[pRoot] += size[qRoot];
      }

      --count;
    }
    bool connected(int p, int q) {
      int pRoot = find(p);
      int qRoot = find(q);

      if (pRoot == qRoot)
        return true;
      else
        return false;
    }
    int find(int x) {
      while (parent[x] != x) {
        // compress the route
        parent[x] = parent[parent[x]];
        x = parent[x];
      }

      return x;
    }
  };
  bool equationsPossible(vector<string>& equations) {
    UF uf(26);

    for (auto& eq : equations) {
      if (eq[1] == '=') {
        uf.unionf(eq[0] - 'a', eq[3] - 'a');
      }
    }
    for (auto& eq : equations) {
      if (eq[1] == '!' && uf.connected(eq[0] - 'a', eq[3] - 'a')) {
        return false;
      }
    }

    return true;
  }
};
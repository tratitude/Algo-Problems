// Time complexity: O(N)
// Space complexity: O(N)
// N: number of edges
class Solution {
  using pii = pair<int, int>;
  const pii null_pii = {0, 0};
  vector<int> parent;
  vector<int> size;

 public:
  pii unionf(int p, int q) {
    auto ans = null_pii;
    int p_root = find(p);
    int q_root = find(q);

    if (p_root == q_root) {
      ans = {p, q};
      return ans;
    }

    if (size[p_root] > size[q_root]) {
      parent[q_root] = p_root;
      size[p_root] += size[q_root];
    } else {
      parent[p_root] = q_root;
      size[q_root] += size[p_root];
    }

    return ans;
  }
  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }

    return x;
  }
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int N = edges.size();
    vector<int> ans;
    // init parent and size
    for (int i = 0; i <= N; i++) {
      parent.push_back(i);
      size.push_back(0);
    }

    for (auto& edge : edges) {
      auto res = unionf(edge[0], edge[1]);
      if (res != null_pii) {
        ans.push_back(res.first);
        ans.push_back(res.second);
        break;
      }
    }

    return ans;
  }
};
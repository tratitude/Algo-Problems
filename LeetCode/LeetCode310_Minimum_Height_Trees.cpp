// Approach: BFS for each root node, store graph as adjacent list
// Time complexity: O(N^2)
// Space complexity: O(N)
// N: number of vertices
// Status: TLE
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> ans;
    int min_height = n;
    vector<vector<int>> adj_list(n);

    // init adj_list
    for (auto& edge : edges) {
      adj_list[edge[0]].emplace_back(edge[1]);
      adj_list[edge[1]].emplace_back(edge[0]);
    }

    for (int root = 0; root < n; root++) {
      vector<bool> seen(n, false);
      int height = 0;
      // next node, next height
      queue<pair<int, int>> q;
      q.push({root, height});
      seen[root] = true;

      while (!q.empty()) {
        auto [cur_node, cur_height] = q.front();
        q.pop();

        // update height
        height = cur_height;

        for (int next_node : adj_list[cur_node]) {
          if (!seen[next_node]) {
            q.push({next_node, cur_height + 1});
            seen[next_node] = true;
          }
        }
      }

      if (height == min_height) {
        ans.emplace_back(root);
      } else if (height < min_height) {
        min_height = height;
        ans.clear();
        ans.emplace_back(root);
      }
    }

    return ans;
  }
};

// Approach: Topological sort with adjacency list
// Time complexity: O(N)
// Space complexity: O(N)
// N: number of vertices
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    // edge case
    if (n == 1) {
      return {0};
    } else if (n == 2) {
      return {0, 1};
    }

    unordered_map<int, unordered_set<int>> adj_list;

    // init adj_list
    for (auto& edge : edges) {
      adj_list[edge[0]].insert(edge[1]);
      adj_list[edge[1]].insert(edge[0]);
    }

    queue<int> leaves;

    // push 1 degree nodes
    for (auto& [node, list] : adj_list) {
      if (list.size() == 1) {
        leaves.push(node);
      }
    }

    while (n > 2) {
      n -= leaves.size();

      queue<int> next_leaves;
      while (!leaves.empty()) {
        int leaf = leaves.front();
        leaves.pop();

        for (int node : adj_list[leaf]) {
          adj_list[node].erase(leaf);
          if (adj_list[node].size() == 1) {
            next_leaves.push(node);
          }
        }
        adj_list.erase(leaf);
      }
      leaves = next_leaves;
    }

    vector<int> ans;
    for (auto& [node, list] : adj_list) {
      ans.emplace_back(node);
    }

    return ans;
  }
};

// Approach: Topological sort with adjacency list
// Time complexity: O(N)
// Space complexity: O(N)
// N: number of vertices
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    // edge case
    if (n == 1) {
      return {0};
    } else if (n == 2) {
      return {0, 1};
    }

    vector<vector<int>> adj_list(n);
    vector<int> degs(n, 0);

    // init adj_list and degs
    for (auto& edge : edges) {
      adj_list[edge[0]].emplace_back(edge[1]);
      adj_list[edge[1]].emplace_back(edge[0]);
      degs[edge[0]]++;
      degs[edge[1]]++;
    }

    queue<int> leaves;

    // push 1 order nodes
    for (int i = 0; i < degs.size(); i++) {
      if (degs[i] == 1) {
        leaves.push(i);
      }
    }

    while (n > 2) {
      int leaves_size = leaves.size();
      n -= leaves_size;

      for (int i = 0; i < leaves_size; i++) {
        int leaf = leaves.front();
        leaves.pop();

        degs[leaf]--;
        for (int node : adj_list[leaf]) {
          if (--degs[node] == 1) {
            leaves.push(node);
          }
        }
      }
    }

    vector<int> ans;
    while (!leaves.empty()) {
      ans.emplace_back(leaves.front());
      leaves.pop();
    }

    return ans;
  }
};
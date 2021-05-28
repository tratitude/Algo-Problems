#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// DFS approach
// Time complexity: O(e*v), Space complexity: O(e)
// e: number of edges
// v: number of vertices
/*
class Solution {
 public:
  void dfs(int cur, const vector<vector<int>>& graph, vector<int>& path,
           vector<vector<int>>& res) {
    path.push_back(cur);

    if (cur + 1 == graph.size()) {
      res.push_back(path);
      path.pop_back();
      return;
    }

    for (const auto& node : graph[cur]) {
      dfs(node, graph, path, res);
    }

    path.pop_back();
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> path;
    vector<vector<int>> res;

    dfs(0, graph, path, res);

    return res;
  }
};
*/
/***************************************************************************/
// Topological sort and DP approach
// Time complexity: Topological sort: O(e+v), allPathsSourceTarget: O(v^2 + v*e)
// Space complexity: O(e*v)
// e: number of edges
// v: number of vertices
class Solution {
 public:
  vector<int> topoSort(const vector<vector<int>>& graph) {
    vector<int> count(graph.size(), 0);
    queue<int> q;
    vector<int> res;
    for (int i = 0; i < graph.size(); ++i) {
      for (int j = 0; j < graph[i].size(); ++j) {
        ++count[graph[i][j]];
      }
    }
    for (int i = 0; i < graph.size(); ++i) {
      if (count[i] == 0) q.push(i);
    }

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      res.push_back(node);

      for (int i = 0; i < graph[node].size(); ++i) {
        if (--count[graph[node][i]] == 0) q.push(graph[node][i]);
      }
    }
    return res;
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<vector<int>>> dp(n);
    dp[n - 1] = {{n - 1}};

    auto sorted = topoSort(graph);

    for (int from = n - 2; from >= 0; --from) {
      int fromNode = sorted[from];
      for (int i = 0; i < graph[fromNode].size(); ++i) {
        int toNode = graph[fromNode][i];
        for (int j = 0; j < dp[toNode].size(); ++j) {
          vector<int> path = {fromNode};
          for (const auto& node : dp[toNode][j]) {
            path.push_back(node);
          }
          dp[fromNode].push_back(path);
        }
      }
    }

    return dp[0];
  }
};
int main() {
  Solution sol;
  vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
  auto res = sol.allPathsSourceTarget(graph);

  for (auto& vec : res) {
    for (auto& node : vec) {
      cout << node << " ";
    }
    cout << "\n";
  }
}
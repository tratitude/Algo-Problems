#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nodeNum(pair<int, int>& p, bool small)
{
  return small ? p.first : p.second;
}

int find(vector<vector<int>>& graph, vector<pair<int, int>>& nodes, bool small)
{
  int n = graph.size();
  int num = 0;
  vector<bool> seen(n, false);

  queue<pair<int, bool>> q;
  q.push({0, small});
  while(!q.empty()) {
    auto [id, isSmall] = q.front();
    q.pop();

    int cur = nodeNum(nodes[id], isSmall);

    seen[id] = true;
    isSmall = !isSmall;

    for(auto& nextID : graph[id]) {
      if(seen[nextID])
        continue;
      int next = nodeNum(nodes[nextID], isSmall);
      num += abs(next - cur);
      q.push({nextID, isSmall});
    }
  }
  return num;
}

int main()
{
  int t=0, n=0, l=0, r=0;

  cin >> t;
  while(t--) {
    cin >> n;
    vector<vector<int>> graph(n);
    vector<pair<int, int>> nodes(n);
    for(int i=0; i<n; ++i) {
      cin >> l >> r;
      nodes[i] = {l, r};
    }
    for(int i=0; i<n-1; ++i) {
      cin >> l >> r;
      graph[l-1].push_back(r-1);
      graph[r-1].push_back(l-1);
    }

    int maxNum = 0;
    maxNum = max(maxNum, find(graph, nodes, true));
    maxNum = max(maxNum, find(graph, nodes, true));

    cout << maxNum << "\n";
  }
}
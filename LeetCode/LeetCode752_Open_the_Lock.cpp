#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// Time complexity: O(10^5)
// Space complexity: O(10^5)
class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    const int Max = 1e5;
    bool isEnd[Max] = {false};
    int next[2] = {1, 9};
    string start("0000");
    // init isEnd
    for (auto& s : deadends) isEnd[stoi(s)] = true;

    queue<pair<string, int>> q;
    if (!isEnd[stoi(start)]) {
      q.push(make_pair(start, 0));
      isEnd[stoi(start)] = true;
    }

    while (!q.empty() && q.front().first != target) {
      auto [curNum, turn] = q.front();
      q.pop();

      for (int i = 0; i < 4; ++i) {
        for (int n : next) {
          string nextNum(curNum);
          nextNum[i] = (n + curNum[i] - '0') % 10 + '0';
          if (!isEnd[stoi(nextNum)]) {
            q.push(make_pair(nextNum, turn + 1));
          }
          isEnd[stoi(nextNum)] = true;
        }
      }
    }
    return q.empty() ? -1 : q.front().second;
  }
};

int main() {
  Solution sol;
  vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
  string target("0202");

  cout << sol.openLock(deadends, target);
}
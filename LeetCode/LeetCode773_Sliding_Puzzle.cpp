// Time complexity: O(3^6 / 2)
// Space complexity: O(3*2)
class Solution {
  struct BoardState {
    string board;
    int zero;
    int count;
    bool isBegin;
  };

 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    string begin, end("123450");
    for (auto& v : board) {
      for (auto& n : v) {
        begin += to_string(n);
      }
    }
    if (begin.compare(end) == 0) return 0;

    vector<vector<int>> nextTable = {{1, 3}, {0, 2, 4}, {1, 5},
                                     {0, 4}, {1, 3, 5}, {2, 4}};
    queue<BoardState> q;
    // board -> {isBegin, count}
    unordered_map<string, pair<bool, int>> mp;
    // init q, mp
    // find zero
    int zeroBegin = begin.find('0');
    q.push({begin, zeroBegin, 0, true});
    q.push({end, 5, 0, false});
    mp[begin] = {true, 0};
    mp[end] = {false, 0};

    while (!q.empty()) {
      auto [curBoard, curZero, curCount, curIsBegin] = q.front();
      q.pop();

      // update curCount
      ++curCount;

      // find next
      for (const auto& nextZero : nextTable[curZero]) {
        swap(curBoard[curZero], curBoard[nextZero]);

        if (mp.count(curBoard)) {
          auto [nextIsBegin, nextCount] = mp[curBoard];
          // found ans
          if (curIsBegin != nextIsBegin) {
            return curCount + nextCount;
          }
        } else {
          mp[curBoard] = {curIsBegin, curCount};
          q.push({curBoard, nextZero, curCount, curIsBegin});
        }

        swap(curBoard[curZero], curBoard[nextZero]);
      }
    }
    return -1;
  }
};
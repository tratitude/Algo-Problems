// Time complexity:
//   constructor: O(N)
//   pick: O(1)
// Space complexity:　O(N)
// N: size of blacklist
class Solution {
  // blacklist index -> none blacklist index that >= size
  unordered_map<int, int> mp;
  // random number [0, size)
  int size;

 public:
  Solution(int n, vector<int>& blacklist) {
    size = n - blacklist.size();

    // insert element in blacklist that >= size
    for (int num : blacklist) {
      if (num >= size) mp[num] = num;
    }
    // map other element that < size to the end
    int end = n - 1;
    for (int num : blacklist) {
      if (num < size) {
        while (mp.count(end)) {
          --end;
        }
        mp[num] = end;
        --end;
      }
    }
  }

  int pick() {
    int num = rand() % size;
    if (mp.count(num)) return mp[num];
    return num;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
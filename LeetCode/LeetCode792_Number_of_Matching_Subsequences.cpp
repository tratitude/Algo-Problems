// Time complexity: O(M)
// Space complexity: O(N)
// N: length of s
// M: number of character in words
class Solution {
 public:
  int numMatchingSubseq(string s, vector<string>& words) {
    vector<deque<int>> vec(26);
    int ans = 0;

    // init vec
    for (int i = 0; i < s.size(); i++) {
      vec[s[i] - 'a'].push_back(i);
    }

    for (auto& word : words) {
      vector<int> flag(26, 0);
      if (!vec[word[0] - 'a'].size()) continue;
      int prev = vec[word[0] - 'a'].front();
      ++flag[word[0] - 'a'];
      // edge case
      if (word.size() == 1) {
        ++ans;
        continue;
      }
      int j;
      for (j = 1; j < word.size(); j++) {
        auto& v = vec[word[j] - 'a'];
        auto& f = flag[word[j] - 'a'];
        if (!v.size()) break;
        while (f != v.size() && v[f] < prev) ++f;

        if (v[f] <= prev) break;
        // update prev
        prev = v[f];
        // update f
        ++f;
      }
      if (j == word.size()) ++ans;
    }

    return ans;
  }
};
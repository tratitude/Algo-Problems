// Time complexity: O(M*N^2)
// Space complexity: O(M)
// M: size of words
// N: length of string
class Solution {
 public:
  bool isPal(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
      if (s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
  }
  vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string, int> mp;
    vector<vector<int>> res;
    for (int i = 0; i < words.size(); ++i) {
      string s(words[i].rbegin(), words[i].rend());
      mp[s] = i;
    }

    if (mp.count("")) {
      int idx = mp[""];
      for (int i = 0; i < words.size(); ++i) {
        if (!words[i].empty() && isPal(words[i])) {
          res.push_back({i, idx});
        }
      }
    }
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words[i].size(); ++j) {
        string left(words[i].begin(), words[i].begin() + j + 1);
        string right = words[i].substr(j + 1);
        if (mp.count(left) && mp[left] != i && isPal(right)) {
          res.push_back({i, mp[left]});
        }
        if (mp.count(right) && mp[right] != i && isPal(left)) {
          res.push_back({mp[right], i});
        }
      }
    }
    return res;
  }
};
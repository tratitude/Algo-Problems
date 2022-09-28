class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    vector<int> s2t(256, -1);
    vector<int> t2s(256, -1);

    for (int i = 0; i < s.size(); i++) {
      int val_t = s2t[s[i]];
      int val_s = t2s[t[i]];

      if (val_t == -1 && val_s == -1) {
        s2t[s[i]] = t[i];
        t2s[t[i]] = s[i];
      } else if (val_t != t[i] && val_s != s[i]) {
        return false;
      }
    }

    return true;
  }
};
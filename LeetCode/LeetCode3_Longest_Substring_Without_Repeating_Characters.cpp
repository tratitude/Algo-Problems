// Sliding window
// Time complexity: O(N)
// Space complexity: O(n)
// N: max node numbers of l1 and l2
int lengthOfLongestSubstring(string s) {
  int l = 0, r = 0, res = 0;
  unordered_map<char, int> m;
  while (r < s.size()) {
    ++m[s[r]];
    if (m[s[r]] > 1) {
      while (m[s[r]] > 1) {
        --m[s[l++]];
      }
      res = res > (r - l + 1) ? res : r - l + 1;
    } else
      res = res > (r - l + 1) ? res : r - l + 1;
    ++r;
  }
  return res;
}

// Brute force
// Time complexity: O(N^2)
// Space complexity: O(N)
// N: max node numbers of l1 and l2
int lengthOfLongestSubstring(string s) {
  if (s.size() == 1) return 1;
  int maxLen = 0;
  for (int i = 0; i < s.size(); ++i) {
    int len = 1;
    set<int> alphabet;
    alphabet.insert(s[i]);
    for (int j = i + 1; j < s.size(); ++j) {
      auto it = alphabet.find(s[j]);
      if (it != alphabet.end()) {
        maxLen = maxLen > len ? maxLen : len;
        break;
      }
      ++len;
      maxLen = maxLen > len ? maxLen : len;
      alphabet.insert(s[j]);
    }
  }
  return maxLen;
}
// Approach: Two pointer
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n <= 1) return n;

        int sptr = 0, fptr = 1, ans = 1;
        unordered_set<char> record = {s[sptr]};
        while (fptr < n) {
            while (fptr < n && record.find(s[fptr]) == record.end()) {
                record.insert(s[fptr]);
                fptr++;
            }
            ans = max(ans, (int)record.size());
            cout << sptr << " " << fptr << " " << ans << endl;
            if (fptr == n) break;
            while (sptr < fptr && s[sptr] != s[fptr]) {
                record.erase(s[sptr]);
                sptr++;
            }
            sptr++;
            fptr++;
        }
        ans = max(ans, (int)record.size());
        return ans;
    }
};
// Time complexity: O(N)
// Space complexity: O(1)
// N: length of s
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> window(256, 0);
    bool invalid = false;
    int left = 0, right = 0, ans = 0;

    while (right < s.size()) {
      char r = s[right];
      ++right;
      if (window[r])
        invalid = true;
      else
        ans = max(ans, right - left);
      ++window[r];

      while (invalid) {
        char l = s[left];
        ++left;
        if (--window[l] == 1) {
          ans = max(ans, right - left);
          invalid = false;
        }
      }
    }

    return ans;
  }
};

// Time complexity: O(N)
// Space complexity: O(1)
// N: length of s
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> window(256, 0);
    int left = 0, right = 0;
    bool rep = false;
    int res = 0;

    while (right < s.size()) {
      char r = s[right];
      ++right;
      if (++window[r] == 2) rep = true;

      while (rep) {
        char l = s[left];
        ++left;
        if (--window[l] == 1) rep = false;
      }

      // update res
      res = max(res, right - left);
    }
    return res;
  }
};
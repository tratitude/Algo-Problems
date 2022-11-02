// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    int longestPalindrome(string s) {
        int record[256] = {0};

        for (auto c : s) {
            ++record[c];
        }

        bool hasOdd = false;
        int ans = 0;
        for (int i = 0; i < 256; i++) {
            if (record[i] % 2 == 1) {
                hasOdd = true;
                record[i]--;
            }
            ans += record[i];
        }

        return hasOdd ? ans + 1 : ans;
    }
};
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
 public:
  int longestPalindrome(string s) {
    vector<int> record(256, 0);
    bool hasOdd = false;
    int ans = 0;

    for (auto c : s) {
      ++record[c];
    }

    for (auto num : record) {
      if (!hasOdd) hasOdd = num % 2;
      ans += num / 2;
    }

    return hasOdd ? ans * 2 + 1 : ans * 2;
  }
};
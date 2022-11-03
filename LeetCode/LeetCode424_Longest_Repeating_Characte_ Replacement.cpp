// Time complexity: O(N)
// Space complexity: O(1)
/*
1. Iterate the left pointer with fixing dynamic right pointer to find valid substring.

len - count of max_element <= k

AABABBA
l  r
 l r
  lr
   lr
    l
     lr
      l
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0, ans = 0;
        vector<int> window(26, 0);

        for (int l = 0; l < s.size(); l++) {
            while (r < s.size() && isValid(window, s, l, r, k)) {
                r++;
            }

            ans = max(ans, r - l);

            window[s[l]-'A']--;
        }
        return ans;
    }
    bool isValid(vector<int>& window, string& s, int l, int r, int k) {
        window[s[r]-'A']++;
    
        if (r - l + 1 - *max_element(window.begin(), window.end()) > k) {
            window[s[r]-'A']--;
            return false;
        }
        return true;
    }
};
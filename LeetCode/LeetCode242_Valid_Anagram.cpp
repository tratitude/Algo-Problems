// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) return false;
        }
        return true;
    }
};
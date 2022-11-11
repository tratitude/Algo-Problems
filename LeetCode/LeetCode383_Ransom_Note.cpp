// Time complexity: O(N+M)
// Space complexity: O(1)
// N: size of ransomNote
// M: size of magazine
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};

        for (auto c : magazine)
            record[c - 'a']++;
        
        for (auto c : ransomNote)
            record[c - 'a']--;

        for (int i = 0; i < 26; i++)
            if (record[i] < 0)
                return false;
        return true;
    }
};
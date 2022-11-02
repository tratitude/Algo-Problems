// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int front = 0, end = n - 1;
        bool ans = true;
        while (front <= end && ans) {
            while (front < n && !isalnum(s[front])) front++;
            while (end >= 0 && !isalnum(s[end])) end--;
            // cout << front << " " << end << endl;
            if (front <= end) {
                char fchar = tolower(s[front]), echar = tolower(s[end]);
                ans &= fchar == echar;
                front++;
                end--;
            }
        }
        return ans;
    }
};
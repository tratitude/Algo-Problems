// Time complexity: O(N)
// Space complexity: O(1)
// Same idea from 424. Longest Repeating Character Replacement
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0, ans = 0;
        vector<int> count(2, 0);

        for (int right = 0; right < answerKey.size(); right++) {
            count[toIdx(answerKey, right)]++;
            while (right - left + 1 - *max_element(count.begin(), count.end()) > k) {
                count[toIdx(answerKey, left)]--;
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
    int toIdx(string& s, int idx) {
        if (s[idx] == 'T') return 1;
        else return 0;
    }
};
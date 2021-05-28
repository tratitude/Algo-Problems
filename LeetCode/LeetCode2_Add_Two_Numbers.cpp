#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
/*
// Brute force
// Time complexity: O(n^2), Space complexity: O(n)
int lengthOfLongestSubstring(string s) {
    if(s.size() == 1)
        return 1;
    int maxLen = 0;
    for(int i=0; i<s.size(); ++i){
        int len = 1;
        set<int> alphabet;
        alphabet.insert(s[i]);
        for(int j=i+1; j<s.size(); ++j){
            auto it = alphabet.find(s[j]);
            if(it!=alphabet.end()){
                maxLen = maxLen>len ? maxLen : len;
                break;
            }
            ++len;
            maxLen = maxLen>len ? maxLen : len;
            alphabet.insert(s[j]);
        }
    }
    return maxLen;
}
*/
// Sliding window
// Time complexity: O(n), Space complexity: O(n)
int lengthOfLongestSubstring(string s) {
    int l=0, r=0, res=0;
    unordered_map<char, int> m;
    while(r<s.size()){
        ++m[s[r]];
        if(m[s[r]] > 1){
            while(m[s[r]] > 1){
                --m[s[l++]];
            }
            res = res>(r-l+1) ? res : r-l+1;
        }
        else
            res = res>(r-l+1) ? res : r-l+1;
        ++r;
    }
    return res;
}
int main()
{
    string s("123415");
    cout << lengthOfLongestSubstring(s);
}
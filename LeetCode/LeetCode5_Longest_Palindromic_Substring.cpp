#include <string>
#include <utility>
#include <iostream>
using namespace std;
// longest common substring

// DP

// Extend around center

// Manacher's Algorithm

// Brute force
// Time complexity: O(n^3), Space complexity: O(1)
string longestPalindrome(string s) {
    auto longest = string(1, s[0]);
    for(int windowSize = s.size(); windowSize > 1; --windowSize){
        int left = 0, right = windowSize-1;
        bool odd = (right-left+1)%2;
        while(right < s.size()){
            int mid = (right+left)/2;
            // is even
            int checkl = mid, checkr = mid+1;
            if(odd)
                checkl = mid-1;
            while(checkr <= right){
                if(s[checkl] != s[checkr])
                    break;
                if(checkr == right){
                    return string(s.begin()+left, s.begin()+right+1);
                }
                ++checkr; --checkl;
            }
            ++right; ++left;
        }
    }
    return longest;
}

int main()
{
    cout << longestPalindrome("cbbd");
}
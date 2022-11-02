// Time complexity: O(M*log(M)*N)
// Space complexity: O(N)
// N: strs.size()
// M: strs[i].size()
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> dic;
        vector<vector<string>> ans;

        for (auto& str : strs) {
            string sortStr(str);
            sort(sortStr.begin(), sortStr.end());
            if (dic.count(sortStr) == 0) {
                dic[sortStr] = ans.size();
                ans.push_back({str});
            } else {
                int idx = dic[sortStr];
                ans[idx].push_back(str);
            }
        }
        return ans;
    }
};
// Time complexity: O(M*N)
// Space complexity: O(N)
// N: strs.size()
// M: strs[i].size()
/*
dic: {{"eat", 0}}
ans: {{"eat"}}

dic: {{"eat", 0}}
ans: {{"eat", "tea"}}
*/
class MyString {
public:
    string _s;
    size_t _dic[26] = {0};
    MyString(string& s): _s(s) {
        for (char c : s) {
            _dic[c-'a']++;
        }
    }
    MyString(string&& s): _s(s) {
        for (char c : s) {
            _dic[c-'a']++;
        }
    }
    ~MyString() {}
    size_t size() const {
        return _s.size();
    }
};
bool operator==(const MyString& lhs, const MyString& rhs) {
    if (lhs.size() != rhs.size()) return false;
    for (int i = 0; i < 26; i++) {
        if (lhs._dic[i] != rhs._dic[i])
            return false;
    }
    return true;
}
bool operator!=(const MyString& lhs, const MyString& rhs) {
    return !(lhs == rhs);
}
struct MyHash {
    size_t operator()(const MyString& str) const {
        size_t val = 0;
        for (int i = 0; i < 26; i++) {
            val ^= str._dic[i] << i;
        }
        return val;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<MyString, int, MyHash> dic;
        vector<vector<string>> ans;

        for (auto& str : strs) {
            MyString myStr(str);
            if (dic.count(myStr) == 0) {
                dic[myStr] = ans.size();
                ans.push_back({str});
            } else {
                int idx = dic[myStr];
                ans[idx].push_back(str);
            }
        }
        return ans;
    }
};
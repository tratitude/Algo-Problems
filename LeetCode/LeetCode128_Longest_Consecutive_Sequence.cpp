#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
  vector<int> parent;
  vector<int> size;

 public:
  void unionf(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);

    if (rootP == rootQ) return;
    if (size[rootP] > size[rootQ]) {
      parent[rootQ] = rootP;
      size[rootP] += size[rootQ];
    } else {
      parent[rootP] = rootQ;
      size[rootQ] += size[rootP];
    }
  }
  int find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  int longestConsecutive(vector<int>& nums) {
    if (!nums.size()) return 0;
    // nums[i] -> i
    unordered_map<int, int> mp;
    parent.reserve(nums.size());
    size.reserve(nums.size());
    // init mp, parent, size
    for (int i = 0; i < nums.size(); ++i) {
      // parent[i] = i;
      parent.push_back(i);
      // size[i] = 1;
      size.push_back(1);
      mp[nums[i]] = i;
    }

    for (const auto& [num, idx] : mp) {
      if (mp.count(num + 1)) {
        unionf(idx, mp[num + 1]);
      }
      if (mp.count(num - 1)) {
        unionf(idx, mp[num - 1]);
      }
    }
    return *max_element(size.begin(), size.end());
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  cout << sol.longestConsecutive(nums);
}
// Time complexity: O(n)
// Space complexity: O(n)
/*
class Solution {
  class UF {
    int count;
    int* parent;
    int* size;

   public:
    UF(int n) : count(n) {
      parent = new int[n];
      size = new int[n];

      for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
      }
    }
    void unionf(int p, int q) {
      int pRoot = find(p);
      int qRoot = find(q);

      if (pRoot == qRoot) return;

      if (size[pRoot] < size[qRoot]) {
        parent[pRoot] = qRoot;
        size[qRoot] += size[pRoot];
      } else {
        parent[qRoot] = pRoot;
        size[pRoot] += size[qRoot];
      }
    }
    int find(int x) {
      while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
      }
      return x;
    }
    int maxUnion() {
      int maxNum = 0;
      for (int i = 0; i < count; ++i) {
        maxNum = max(maxNum, size[i]);
      }
      return maxNum;
    }
  };

 public:
  int longestConsecutive(vector<int>& nums) {
    UF uf(nums.size());
    unordered_map<int, int> um;

    for (int i = 0; i < nums.size(); ++i) {
      um[nums[i]] = i;
    }

    for (auto& num : nums) {
      if (um.count(num + 1) > 0) {
        uf.unionf(um[num], um[num + 1]);
      }
      if (um.count(num - 1) > 0) {
        uf.unionf(um[num], um[num - 1]);
      }
    }

    return uf.maxUnion();
  }
};
*/
// simple unordered_set approach, same as O(n)
/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        const int n=nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        int res=1;
        int num=0;
        for(auto& num:nums){
            s.erase(num);
            int prev=num-1,next=num+1;
            while(s.count(prev)){
                s.erase(prev);
                prev--;
            }
            while(s.count(next)){
                s.erase(next);
                next++;
            }
            res=max(res,next-prev-1);
        }
        return res;
    }
};
*/
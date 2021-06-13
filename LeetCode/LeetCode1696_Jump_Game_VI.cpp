#include <vector>
#include <queue>
#include <iostream>
using namespace std;
// Time complexity: O(N*log(N))
// Space complexity: O(N)
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    int res = 0;

    for (int i = nums.size() - 1; i >= 0; --i) {
      int end = i + k <= nums.size() - 1 ? i + k : nums.size() - 1;

      while (!pq.empty() && pq.top().second > end) pq.pop();

      int maxNum = pq.empty() ? 0 : pq.top().first;

      // update pq
      pq.push(make_pair(nums[i] + maxNum, i));
      if(i == 0)
        res = nums[i] + maxNum, i;
    }
    return res;
  }
};

int main(){
  vector<int> nums = {-3, -1 - 1, -1, -1};
  int k = 2;
  Solution sol;
  cout << sol.maxResult(nums, k);

}
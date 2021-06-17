#include <vector>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int slow = 0, fast = 0;

    while (fast < nums.size()) {
      if (nums[fast] != 0) {
        nums[slow] = nums[fast];
        ++slow;
      }
      ++fast;
    }
    for (; slow < nums.size(); ++slow) {
      nums[slow] = 0;
    }
  }
};

int main()
{
  vector<int> nums = {1, 0, 2, 3};
  Solution sol;
  sol.moveZeroes(nums);
}
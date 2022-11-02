// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), zero = 0, nzero = 1;
        if (n == 1) return;

        while (zero < n && nzero < n) {
            while (zero < n && nums[zero] != 0) zero++;
            nzero = zero + 1;
            while (nzero < n && nums[nzero] == 0) nzero++;
            if (zero < n && nzero < n) {
                swap(nums[zero], nums[nzero]);
                zero++;
            }
        }
    }
};
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
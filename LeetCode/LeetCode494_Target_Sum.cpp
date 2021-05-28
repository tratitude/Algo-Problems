#include <iostream>
#include <vector>
using namespace std;

// Backtrack
// Time complexity: O(2^(1+N)), Space complexity: O(N)
// N: nums.size()
void backtrack(const vector<int>& nums, int idx, int target, int& result)
{
    // base case
    if(idx == nums.size()){
        if(target == 0)
            ++result;
        return;
    }

    // select add
    target += nums[idx];
    backtrack(nums, idx+1, target, result);
    // recover
    target -= nums[idx];

    // select minus
    target -= nums[idx];
    backtrack(nums, idx+1, target, result);
    // recover
    target += nums[idx];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int result = 0;
    backtrack(nums, 0, target, result);
    return result;
}

int main()
{
    vector<int> vec = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(vec, 3);
}
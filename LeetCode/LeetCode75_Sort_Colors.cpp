// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counter[3] = {0};

        for (auto num : nums) {
            counter[num]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i < counter[0])
                nums[i] = 0;
            else if (i >= counter[0] && i < counter[0] + counter[1])
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};
// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int j = 0 , k = nums.size() -1;
        for(int i = 0; i <= k; i++)
        {
            if(nums[i] == 0)
            {
                swap(nums[i] , nums[j++]);
            }
            else if(nums[i] == 2)
            {
                swap(nums[i--], nums[k--]);
            }
        }
    }
};
/*
// Brute force
// Time complexity: O(n^2), Space complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(auto i=0; i<nums.size(); ++i){
            for(auto j=i+1; j<nums.size(); ++j){
                if(nums[i]+nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};
// Hash
// Time complexity: O(log(n)), Space complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> m;
        for(int i=0; i<nums.size(); ++i){
            m.insert({nums[i], i});
            auto t = m.find(target-nums[i]);
            if(t!=m.end() && t->second!=i){
                result.push_back(t->second);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};
*/
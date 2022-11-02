// Backtracking approach
// Time complexity: O(N^(target/min(candidates)))
// Space complexity:
/*
7,6,3,2  7
7 t
6,6 f
6,3 f
6,2 f
3,3,3 f
3,3,2 f
3,2,3 f duplicate, can be avoided this branch by selecting the candidate non-before
3,2,2 t
2,2,2,2 f
*/
class Solution {
    vector<vector<int>> ans;
    int _target = 0, n = 0;

    void bt(vector<int>& candidates, vector<int> selected, int pos, int sum) {
        if (sum > _target) {
            return;
        } else if (sum == _target) {
            ans.push_back(selected);
            return;
        }
        for (int i = pos; i < n; i++) {
            sum += candidates[i];
            selected.push_back(candidates[i]);
            bt(candidates, selected, i, sum);
            selected.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        _target = target;
        n = candidates.size();
        sort(candidates.begin(), candidates.end(), greater<int>());
        // for (auto& can : candidates)
        //     cout << can << endl;
        bt(candidates, {}, 0, 0);
        return ans;
    }
};
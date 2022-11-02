// Time complexity: O(N)
// Space complexity: O(N)
// N: size of intervals
class Solution {
    bool isOverlap(vector<int>& vec1, vector<int>& vec2) {
        return !(vec1[1] < vec2[0] || vec2[1] < vec1[0]);
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for (auto& interval : intervals) {
            if (isOverlap(interval, newInterval)) {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            } else {
                if (interval[1] < newInterval[0]) {
                    ans.emplace_back(interval);
                } else {
                    ans.emplace_back(newInterval);
                    ans.emplace_back(interval);
                    newInterval[0] = newInterval[1] = INT_MAX;
                }
            }
            //cout << newInterval[0] << " " << newInterval[1] << endl;
        }
        if (newInterval[0] != INT_MAX) {
            ans.emplace_back(newInterval);
        }
        return ans;
    }
};

/*
## overlap
case 1
  [  ]
[      ]

case 2
[    ]
  []
  
case 3
[ ]
 [  ]
 
case 4
  [  ]
[  ]

## non-overlap
case 1
[ ]
    []
case 2
    [ ]
[]

demorgen
!(a || b)
0 0 1
1 0 0
0 1 0
1 1 0
(!a && !b)
0 0 1

*/
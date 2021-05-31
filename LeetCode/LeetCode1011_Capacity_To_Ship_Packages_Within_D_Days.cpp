// Time complexity: O(N*log(M))
// N: number of weights
// M: (summation of weights) - (max value of weights)
class Solution {
 public:
  bool isValid(vector<int>& weights, int days, int weight) {
    // backtracking version
    /*
    // the total weights of ship i
    vector<int> ship(days, 0);
    // record whether belts were loaded
    vector<bool> loaded(weights.size(), false);

    for(int belt : weights) {
        // belt can put in ship

        // belt can't put in any ship
        for(int& s : ship) {

        }
    }
    */
    int belt = 0;
    for (int d = 0; d < days; ++d) {
      int maxW = weight;
      while ((maxW -= weights[belt]) >= 0) {
        if (++belt == weights.size()) return true;
      }
    }
    return false;
  }
  int shipWithinDays(vector<int>& weights, int days) {
    int right = 0;
    int left = weights[0];

    for (int w : weights) {
      left = max(left, w);
      right += w;
    }

    // special case
    if (days == 1) return right;

    // binary search in [left, right]
    while (left <= right) {
      int mid = left + (right - left) / 2;

      // left is valid
      if (isValid(weights, days, mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};
// sample 20 ms submission
/*
#pragma GCC optimize("Ofast")
static const auto fast = []() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
   std::cout.tie(0);
   return 0;
} ();
class Solution {
public:
    vector<int> arr;
    inline int day(int cap) {
        int cnt = 1, tmp = cap;
        for(int i: arr) {
            if(i <= tmp) tmp -= i;
            else tmp = cap - i, ++cnt;
        }
        return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        arr = move(weights);
        int l = *max_element(arr.begin(), arr.end()), r = 25 * 1e6;
        while(l < r) {
            int mid = (l + r) / 2;

            if(day(mid) > days) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
*/
// Time complexity: O(N*log(N))
// Space complexity: O(1)
// N: size of boxTypes
class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(),
         [](auto& l, auto& r) { return l.back() > r.back(); });

    int res = 0;
    for (auto& box : boxTypes) {
      if (truckSize == 0) break;
      if (truckSize < box[0]) {
        res += truckSize * box[1];
        truckSize = 0;
      } else {
        res += box[0] * box[1];
        truckSize -= box[0];
      }
    }
    return res;
  }
};
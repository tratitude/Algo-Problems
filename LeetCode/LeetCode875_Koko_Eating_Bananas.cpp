// Time complexity: O(Nlog(N))
// Space complexity: O(1)
class Solution {
 public:
  bool find(vector<int>& piles, int h, int k) {
    int sum = 0;

    for (int p : piles) sum += ceil(double(p) / k);
    // slower but less memory usage
    /*
    for(int p : piles) {
        sum += p/k;
        sum += p%k == 0 ? 0 : 1;
    }
    */
    return sum <= h;
  }
  int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int maxK = *(max_element(piles.begin(), piles.end()));

    // specail case
    if (h == n) return maxK;

    int minK = 1;
    // binary search in [minK, maxK) and [minK, maxK] both are acceptable
    while (minK < maxK) {
      int mid = minK + (maxK - minK) / 2;
      // find in left
      if (find(piles, h, mid)) {
        maxK = mid;
      } else {
        minK = mid + 1;
      }
    }

    return minK;
  }
};
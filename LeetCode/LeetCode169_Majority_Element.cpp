// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int elem = 0, count = 0;

    for (int num : nums) {
      if (count == 0) elem = num;

      if (num == elem)
        ++count;
      else
        --count;
    }

    return elem;
  }
};

// Time complexity: O(N)
// Space complexity: O(N)
// N: size of nums
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    stack<int> st;

    for (auto num : nums) {
      if (st.empty() || st.top() == num) {
        st.push(num);
      } else {
        st.pop();
      }
    }

    return st.top();
  }
};
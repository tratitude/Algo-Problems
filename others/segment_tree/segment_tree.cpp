#include <vector>
#include <iostream>

using namespace std;

//* pull() depend on the problem
//* implement the prefix sum as default
class SegmentTree {
  //* N = number of input elements
  int N;
  //* st [1, 4*N]
  vector<int> st;

 public:
  void pull(int index) { st[index] = st[index * 2] + st[index * 2 + 1]; }

  void init(vector<int>& nums) {
    N = nums.size();

    for (int i = 0; i <= N * 4; i++) {
      st.push_back(0);
    }

    init_helper(nums, 1, 0, N - 1);
  }

  //* index: the index of st [1, 4*N], init call as 1
  //* left: left index of nums, init call as 0
  //* right: right index of nums, init call as nums.size() - 1
  void init_helper(vector<int>& nums, int index, int left, int right) {
    if (left == right) {
      st[index] = nums[left];
      return;
    }

    int mid = (left + right) / 2;
    init_helper(nums, index * 2, left, mid);
    init_helper(nums, index * 2 + 1, mid + 1, right);

    pull(index);
  }

  //* query an interval [query_left, query_right]
  //* 1 <= query_left <= query_right <= N
  int query(int query_left, int query_right) {
    return query_helper(query_left, query_right, 1, 1, N);
  }

  //* index: the index of st [1, 4*N], init call as 1
  //* left: valid index of st, init call as 1
  //* right: valid index of st, init call as N
  int query_helper(int query_left, int query_right, int index, int left,
                   int right) {
    if (query_left <= left && query_right >= right) {
      return st[index];
    }

    int ret = 0;
    int mid = (left + right) / 2;

    // find left child
    if (query_left <= mid) {
      ret += query_helper(query_left, query_right, index * 2, left, mid);
    }

    // find right child
    if (query_right > mid) {
      ret += query_helper(query_left, query_right, index * 2 + 1, mid + 1, right);
    }

    return ret;
  }

  //* update val from x to it's parents
  void update(int position, int val) {
    update_helper(position, val, 1, 1, N);
  }

  //* index: the index of st [1, 4*N], init call as 1
  //* left: valid index of st, init call as 1
  //* right: valid index of st, init call as N
  void update_helper(int position, int val, int index, int left,
                     int right) {
    if (left == right) {
      st[index] += val;
      return;
    }

    int mid = (left + right) / 2;
    // find left child
    if (position <= mid) {
      update_helper(position, val, index * 2, left, mid);
    } else { // find right child
      update_helper(position, val, index * 2 + 1, mid + 1, right);
    }

    pull(index);
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  SegmentTree st;
  st.init(nums);
  
  cout << st.query(1, nums.size()) << "\n";
  cout << st.query(2, nums.size()) << "\n";

  st.update(1, 2);
  cout << st.query(1, nums.size()) << "\n";
  cout << st.query(2, nums.size()) << "\n";
}
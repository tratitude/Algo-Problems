#include <set>
#include <iostream>
#include <vector>
using namespace std;
// Time complexity: O(N*log(N))
// Space complexity: O(N)
class MyCalendar {
 public:
  set<pair<int, int>> s;
  bool book(int start, int end) {
    // check if current time interval can be inserted or not
    auto itr = s.lower_bound({start, end});
    if (itr != s.end() and end > itr->first) return false;
    if (itr != s.begin() and (--itr)->second > start) return false;
    s.insert({start, end});
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

 int main()
 {
   MyCalendar cal;
   /*
   vector<pair<int, int>> v = {{47, 50}, {33, 41}, {39, 45}, {33, 42},
                               {25, 32}, {26, 35}, {19, 25}, {3, 8},
                               {8, 13},  {18, 27}};
                              */
  vector<pair<int, int>> v = {{40, 45}, {47, 50}, {44, 46}};                            
  for(auto p : v) {
    cout << cal.book(p.first, p.second) << "\n";
  }
 }
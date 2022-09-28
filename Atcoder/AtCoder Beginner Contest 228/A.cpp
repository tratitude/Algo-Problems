  #include <algorithm>
  #include <iostream>
  #include <vector>

  using namespace std;

  int main() {
    int start, end, dur;
    cin >> start >> end >> dur;
    
    if (start < end) {
      if (start <= dur && dur < end) {
        cout << "Yes";
      } else {
        cout << "No";
      }
    } else if (start > end) {
      if (end <= dur && dur < start) {
        cout << "No";
      } else {
        cout << "Yes";
      }
    } else {
      cout << "No";
    }
  }
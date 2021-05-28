// compile by MSVC++
#include<iostream>
#include<list>
#include <iterator>
#include <algorithm>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;
#define Inf 65536

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.precision(15);
     cout << fixed;

     int size; cin >> size;
     list<int> l;
     int total = 0;

     for (int i = 0; i<size; i++) {
          int num; cin >> num;
          l.push_back(num);
     }
     for (int times = 0; times<size - 1; times++) {
          auto small = l.begin();
          for (auto it = l.begin(); it != l.end(); it++) {
               small = *it < *small ? it : small;
          }
          int left, right;
          if (small == l.begin() && small != prev(l.end())) {
               left = Inf;
               right = *next(small);
          }
          else if (small != l.begin() && small == prev(l.end())) {
               auto tmp = small;
               right = Inf;
               left = *prev(small);
          }
          else if (small != l.begin() && small != prev(l.end())) {
               right = *next(small);
               left = *prev(small);
          }
          total += min(right, left);
          auto it = l.erase(small);
     }
     cout << total << endl;
     //system("pause");
     return 0;
}
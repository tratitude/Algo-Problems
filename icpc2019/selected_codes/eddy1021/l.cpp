// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef LL type;
typedef pair<type,type> Pt;
typedef pair<Pt,Pt> Line;
typedef pair<Pt,type> Circle;
#define X first
#define Y second
#define O first
#define R second
Pt operator+( const Pt& p1 , const Pt& p2 ){
  return { p1.X + p2.X , p1.Y + p2.Y };
}
Pt operator-( const Pt& p1 , const Pt& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
Pt operator*( const Pt& tp , const type& tk ){
  return { tp.X * tk , tp.Y * tk };
}
Pt operator/( const Pt& tp , const type& tk ){
  return { tp.X / tk , tp.Y / tk };
}
type operator*( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
type operator^( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
type norm2( const Pt& tp ){
  return tp * tp;
}
double norm( const Pt& tp ){
  return sqrt( norm2( tp ) );
}
Pt perp( const Pt& tp ){
  return { tp.Y , -tp.X };
}
void scan(Pt& tp) {
  scanf("%lld%lld", &tp.X, &tp.Y);
}
LL cross(Pt o, Pt a, Pt b){
  return (a-o) ^ (b-o);
}
vector<Pt> convex_hull(vector<Pt> pt){
  sort(pt.begin(),pt.end());
  int top=0;
  vector<Pt> stk(2*pt.size());
  for (int i=0; i<(int)pt.size(); i++){
    while (top >= 2 && cross(stk[top-2],stk[top-1],pt[i]) <= 0)
      top--;
    stk[top++] = pt[i];
  }
  for (int i=pt.size()-2, t=top+1; i>=0; i--){
    while (top >= t && cross(stk[top-2],stk[top-1],pt[i]) <= 0)
      top--;
    stk[top++] = pt[i];
  }
  stk.resize(top-1);
  return stk;
}
constexpr int N = 4096;
int n;
vector<Pt> p;
void init() {
#ifdef TEST_TL
  n = 4096;
  p.resize(n);
  for (int i = 0; i < n; ++i) {
    double deg = (double)i / n;
    p[i] = {1e9 * cosl(deg), 1e9 * sinl(deg)};
  }
#else
  scanf("%d", &n);
  p.resize(n);
  for (int i = 0; i < n; ++i) {
    scan(p[i]);
  }
#endif
}
LL area(vector<Pt> pts) {
  LL ret = 0;
  for (size_t i = 0; i < pts.size(); ++i) {
    ret += pts[i] ^ pts[(i + 1) % pts.size()];
  }
  return abs(ret);
}
LL cal() {
  vector<Pt> ch = convex_hull(p);
  if (ch.size() < 3u) {
    return 0;
  }
  if (ch.size() == 3u) {
    LL ans = 0;
    for (auto cand: ch) {
      for (size_t i = 0; i < p.size(); ++i) {
        if (cand == p[i]) {
          swap(p[i], p.back());
          p.pop_back();
          break;
        }
      }
    }
    for (auto i: p) {
      ans = max(ans, area({ch[0], ch[1], ch[2], i}));
      ans = max(ans, area({ch[0], ch[1], i, ch[2]}));
      ans = max(ans, area({ch[0], i, ch[1], ch[2]}));
    }
    return ans;
  }
  n = ch.size();
  LL ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 2, p1 = i + 1, p2 = j + 1; (j + 1) % n != i; ++j) {
      while (cross(ch[i], ch[(p1 + 1) % n], ch[j % n]) >
             cross(ch[i], ch[p1 % n], ch[j % n])) {
        ++p1;
      }
      while (cross(ch[i], ch[j % n], ch[(p2 + 1) % n]) >
             cross(ch[i], ch[j % n], ch[p2 % n])) {
        ++p2;
      }
      ans = max(ans, cross(ch[i], ch[p1 % n], ch[j % n]) +
                     cross(ch[i], ch[j % n], ch[p2 % n]));
    }
  }
  return ans;
}
void solve() {
  LL ans = cal();
  printf("%lld", ans / 2);
  if (ans & 1) {
    printf(".5");
  }
  printf("\n");
}
int main() {
#ifdef TEST_TL
  int t = 10; while (t--) {
#else
  int t; scanf("%d", &t); while (t--) {
#endif
    init();
    solve();
  }
}

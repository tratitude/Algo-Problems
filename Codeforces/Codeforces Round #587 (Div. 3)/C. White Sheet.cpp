#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

typedef long long int lld;
typedef pair<int, int> pii;

struct point{
    int x;
    int y;
};
struct square{
    point lb;
    point rt;
};

#define addPoint(p,x,y) p.x=x; p.y=y;

int checkpoint(vector<point> &check, square &s)
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(15);
    cout << fixed;

    square a, b, c;

    cin >> a.lb.x >> a.lb.y >> a.rt.x >> a.rt.y;
    cin >> b.lb.x >> b.lb.y >> b.rt.x >> b.rt.y;
    cin >> c.lb.x >> c.lb.y >> c.rt.x >> c.rt.y;

    vector<point> check;
    check.push_back(a.lb);
    check.push_back(a.rt);
    point lt, rb;
    addPoint(lt, lb.x, rt.y)
    addPoint(rb, rt.x, lb.y)
    check.push_back(lt);
    check.push_back(rb);

    checkpoint(&check, &a);

    return 0;
}
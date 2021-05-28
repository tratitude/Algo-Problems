/*
13 17
0 5
6 18
24 30
9 21
32 35
11 17
28 29
checking
13 17
0 5
6 18
24 30
9 21
32 35
11 17
28 29
p1 = 2 , 1 , p2 = 2 , 5
4
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define F first
#define S second

const int N = 87;

pii p[N];

int ans = 11;
int a[N][N];
int id[N][N];

typedef vector<pii> vpi;

bool on_board(pii p) {
    return p.F == 0 || p.S == 0 || p.F == 5 || p.S == 5;
}

bool in_board(pii p) {
    return 0 <= min(p.F, p.S) && max(p.F, p.S) < 6;
}

int len(pii p, pii q) {
    return q.F - p.F + q.S - p.S + 1;
}

bool is_corner(pii p) {
    return (p.F == 0 || p.F == 5) && (p.S == 0 || p.S == 5);
}

bool can_leave(pii p1, pii p2) {
    if (p2 == make_pair(2, 5)) return true;
    return false;
    if (on_board(p1) ^ on_board(p2)) return true;
    if (!on_board(p1)) return false;
    if (is_corner(p1) || is_corner(p2)) return true;
    return false;;
}

void check_ok(vpi v, int now) {
    //cout << "checking" << endl;
    /*for (pii p: v) {
        cout << p.F << ' ' << p.S << endl;
    }*/
    pii p1 = p[ v[0].F ], p2 = p[ v[0].S ];
    //cout << "p1 = " << p1.F << " , " << p1.S << " , p2 = " << p2.F << " , " << p2.S << endl;
    if (can_leave(p1, p2)) {
        if (now + len(p1, p2) <= 10) {
            cout << now + len(p1, p2) << endl;
            exit(0);
        }
        else {
            cout << -1 << endl;
            exit(0);
        }
    }
}

int type[7122];

int n;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

pii operator+(pii p1, pii p2) {
    return {p1.F + p2.F, p1.S + p2.S};
}

pii operator*(int x, pii p2) {
    return {x * p2.F, x * p2.S};
}

bool inter(pii p1, pii p2, int t1, pii q1, pii q2, int t2) {
    //cout << "t1 = " << t1 << " , t2 = " << t2 << endl;
    //cout << "p1 = " << p1.F << " , " << p1.S << " , p2 = " << p2.F << " , " << p2.S << endl;
    //cout << "p1 = " << q1.F << " , " << q1.S << " , p2 = " << q2.F << " , " << q2.S << endl;
    for (int i = 0; i < len(p1, p2); ++i) {
        for (int j = 0; j < len(q1, q2); ++j) {
            pii pp = p1 + i * make_pair(dx[ type[t1] ], dy[ type[t1] ]);
            pii qq = q1 + j * make_pair(dx[ type[t2] ], dy[ type[t2] ]);
            //cout << "i = " << i << " , j = " << j << " , pp = " << pp.F << " , " << pp.S << " , qq = " << qq.F << " , " << qq.S << endl;
            if (pp == qq) return true;
        }
    }
    //cout << "did not inter" << endl;
    //if (t2 == 4) exit(0);
    return false;
}

bool move(vpi &v, int idd, int dir) {
    int dd = type[idd] + 2 * dir;
    pii p1 = p[ v[idd].F ], p2 = p[ v[idd].S ] ;
    p1 = p1 + make_pair(dx[dd], dy[dd]);
    p2 = p2 + make_pair(dx[dd], dy[dd]);
    if (!in_board(p1) || !in_board(p2)) return false;
    for (int i = 0; i < n; ++i) {
        if (i == idd) continue;
        if (inter(p1, p2, idd, p[ v[i].F ], p[ v[i].S ], i)) return false;
    }
    v[idd] = make_pair( id[p1.F][p1.S], id[p2.F][p2.S] );
    return true;
}

void gogo(vector<pii> v) {
    check_ok(v, 0);
    map< vector<pii>, int> mp;
    mp[v] = 0;
    queue< vpi > que;
    que.push(v);
    int cnt = 0;
    while (!que.empty()) {
        vpi v = que.front();
        que.pop();
        ++cnt;
        int val = mp[v];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                vpi v2 = v;
                if (move(v2, i, j) && mp.find(v2) == mp.end()) {
                    check_ok(v2, val + 1);
                    mp[v2] = val + 1;
                    que.push(v2);
                }
            }
        }
    }
    //cout << "cnt = " << cnt << endl;
}

int main () {
    int mx = 0;
    int ptr = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> a[i][j];
            id[i][j] = ptr;
            p[ptr] = make_pair(i, j);
            ++ptr;
            mx = max(mx, a[i][j]);
        }
    }
    n = mx;
    vector<pii> v(mx);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (a[i][j] != 0) {
                int gao = a[i][j];
                a[i][j] = 0;
                if (a[i + 1][j] == gao) {
                    for (int ii = i + 1; ii < 6; ++ii) {
                        a[ii][j] = 0;
                        if (a[ii + 1][j] != gao) {
                            v[ gao - 1 ] = make_pair(id[i][j], id[ii][j]);
                            break;
                        }
                    }
                    type[gao - 1] = 0;
                }
                else {
                    for (int jj = j + 1; jj < 6; ++jj) {
                        a[i][jj] = 0;
                        if (a[i][jj + 1] != gao) {
                            v[ gao - 1 ] = make_pair(id[i][j], id[i][jj]);
                            break;
                        }
                    }
                    type[gao - 1] = 1;
                }
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        cout << v[i].F << ' ' << v[i].S << " , type = " << type[i] << endl;
    }*/
    gogo(v);
    if (ans == 11) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}


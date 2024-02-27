#include <bits/stdc++.h>
#define ll long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define N 300005

using namespace std;

int n, q, x, suf[N], sum[N], tot, t[N], l[N], cnt;
map <int,int> rst;
bitset <N> f;

struct ifo {
    int d,s,f;
    friend inline bool operator < (const ifo& A,const ifo& B) {
        return A.s<B.s;
    }
}a[N];


inline void Upt(int x, int y) {
    if (!rst.count(x))
        rst[x] = y;
    else
        rst[x] = min(rst[x],y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i].d >> a[i].f >> a[i].s;
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; -- i) {
        suf[i] = max(suf[i + 1], a[i].f);
        sum[i] = sum[i + 1] + a[i].d;
    }
    Upt(suf[1], sum[1]);
    f.set(0);
    for (int i = 1; i <= n; ++ i) {
        tot += a[i].d; f |= (f << a[i].d);
        ll st = (tot + 1) / 2;
        while (!f.test(st))
            ++ st;
        Upt(max(suf[i + 1], a[i].s), st + sum[i + 1]);
    }
    for (auto [_t,_l]:rst) {
        ++ cnt;
        t[cnt] = _t;
        l[cnt] = _l;
    }
    for (int i = 1; i <= q; ++ i) {
        cin >> x;
        ll L = 1, R = cnt, mid, ret = -1;
        while (L <= R) {
            if (l[mid = L + R >> 1] <= x) {
                ret = t[mid];
                R = mid - 1;
            }
            else
                L = mid + 1;
        }
        cout << ret << endl;
    }

    return 0;
}
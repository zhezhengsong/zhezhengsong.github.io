#include <bits/stdc++.h>
#define ll long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define N 200009
#define M 1000009
#define mod 998244353  //1000000007 1e9+9 984162944621615797 (__int128)
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eps 1e-5
const unsigned seed = 2173412051;

using namespace std;

int T, n, m;
ll c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < 2 * n; ++ i) {
		ll a, b;
		cin >> a >> b;
		ans += max(a, b);
		c[i] = a + b;
	}
	sort(c, c + 2 * n);
	for (int i = 0; i < n; ++ i) {
		ans -= c[i];
	}

	cout << ans << '\n';
	return 0;
}
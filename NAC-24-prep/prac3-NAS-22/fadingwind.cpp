#include <bits/stdc++.h>
#define ll long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define N 10009
#define M 1000009
#define mod 998244353  //1000000007 1e9+9 984162944621615797 (__int128)
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eps 1e-5
const unsigned seed = 2173412051;

using namespace std;

int h, k, v, s, ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> k >> v >> s;

	while (v > 0) {
		
		v += s;
		v -= max(1, v / 10);
		if (v >= k)
			++ h;
		else if (0 < v && v < k) {
			-- h;
			if (h <= 0)
				v = 0;
		}
		else if (v <= 0) {
			v = 0;
			h = 0;
		}
		
		if (s > 0)
			-- s;
		ans += v;
	}
	cout << ans << '\n';
	return 0;
}

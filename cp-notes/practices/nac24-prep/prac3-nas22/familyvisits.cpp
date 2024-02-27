#include <bits/stdc++.h>
#define ll long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define N 1009
#define M 1000009
#define mod 998244353  //1000000007 1e9+9 984162944621615797 (__int128)
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eps 1e-5
const unsigned seed = 2173412051;

using namespace std;

int n, d, m[N], c[N], v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) {
		cin >> m[i] >> c[i];
	}
	v[0] = 0;
	priority_queue <int> op;
	int ans = 0;
	for (int i = 1; i <= d; ++ i) {
		cin >> v[i];
		int cur = 0;
		while (!op.empty()) {
			op.pop();
		}
		for (int j = v[i]; j > v[i - 1]; -- j) {
			cur += m[j];
			op.push(c[j]);
			while (cur > 0 && !op.empty()) {
				int tmp = op.top();
				op.pop();
				ans += 1;
				cur -= tmp;
			}
			if (cur > 0) {
				cout << "-1\n";
				return 0;
			}
		} 
	}
	cout << ans << '\n';
	return 0;
}
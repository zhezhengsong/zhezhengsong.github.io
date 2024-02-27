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
int cnt[5], used[N];
vector <pair<int, int>> ans;
char c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	mst(cnt, 0);
	mst(used, 0);
	for (int i = 1; i <= 2 * n; ++ i) {
		cin >> c[i];
		cnt[c[i] - 'A'] ++;
		// que[c[i] - 'a'].pb(i);
	}

	int num_c = n - cnt[0], num_b = n - cnt[1], num_a = n - cnt[2];
	int j = 2 * n, k = j - 1;
	for (int i = 0; i < num_a; ++ i) {
		while (j > 0 && (c[j] != 'B' || used[j]))
			-- j;
		k = min(k, j - 1);
		while (k > 0 && (c[k] != 'A' || used[k]))
			-- k;
		if (j <= 0 || k <= 0) {
			cout << "NO\n";
			return 0;
		}

		if (c[j] == 'B' && c[k] == 'A') {
			ans.pb(make_pair(k, j));
			used[k] = 1;
			used[j] = 1;
		}
		else {
			cout << "NO\n";
			return 0;
		}
		-- j;
	}

	j = 2 * n; k = j - 1;
	for (int i = 0; i < num_b + num_c; ++ i) {
		while (j > 0 && (c[j] != 'C' || used[j]))
			-- j;
		k = min(k, j - 1);
		while (k > 0 && (c[k] == 'C' || used[k]))
			-- k;
		if (j <= 0 || k <= 0) {
			cout << "NO\n";
			return 0;
		}

		if (c[j] == 'C' && c[k] != 'C') {
			ans.pb(make_pair(k, j));
			used[k] = 1;
			used[j] = 1;
		}
		else {
			cout << "NO\n";
			return 0;
		}
		-- j;
	}
	cout << "YES\n";
	for (auto x : ans) {
		cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}
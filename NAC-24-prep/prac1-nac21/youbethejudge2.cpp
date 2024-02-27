#include <bits/stdc++.h>
#define ll long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define N 1048576
#define M 2009
#define mod 998244353  //1000000007 1e9+9 984162944621615797 (__int128)
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eps 1e-5
const unsigned seed = 2173412051;

using namespace std;

int T, n, m;
int x[M][M], c[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int m = 1;
	for (int i = 0; i < n; ++ i) {
		m = m << 1;
	}
	// cout << m;
	mst(c, 0);
	mst(f, 0);
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			cin >> x[i][j];
			++ c[x[i][j]];
		}
	}
	if (c[0] != 1) {
		cout << "0\n";
		return 0;
	}
	else {
		for (int i = 1; i <= m * m / 3; ++ i) {
			if (c[i] != 0 && c[i] != 3) {
				cout << "0\n";
				return 0;
			}
		}
	}
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			if (x[i][j] == x[i - 1][j] && (x[i][j] == x[i][j - 1] || x[i][j] == x[i][j + 1]) )
				f[x[i][j]] = 1;
			if (x[i][j] == x[i + 1][j] && (x[i][j] == x[i][j - 1] || x[i][j] == x[i][j + 1]) )
				f[x[i][j]] = 1;
		}
		
	}
	for (int i = 1; i <= m * m / 3; ++ i) {
		if (c[i] != 0 && !f[i]) {
			cout << "0\n";
			return 0;
		}
	}
	cout << "1\n";
	return 0;
}
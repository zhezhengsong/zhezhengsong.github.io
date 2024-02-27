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

int T, n, m, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << "i = 2:\n";
	n = 2;
	cnt = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if ((i + j) == i * j) {
				cout << i << ' ' << j << '\n';
				++ cnt;
			}
		}
	}
	cout << "cnt: " << cnt << '\n';

	cout << "i = 3:\n";
	n = 3;
	cnt = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			for (int k = 1; k <= n; ++ k) {
				if ((i + j + k) == i * j * k) {
					cout << i << ' ' << j << ' ' << k << '\n';
					++ cnt;
				}
			}
		}
	}
	cout << "cnt: " << cnt << '\n';

	cout << "i = 4:\n";
	n = 4;
	cnt = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			for (int k = 1; k <= n; ++ k) {
				for (int l = 1; l <= n; ++ l) {
					if ((i + j + k + l) == i * j * k * l) {
						cout << i << ',' << j << ',' << k << ',' << l << '\n';
						++ cnt;
					}
				}
			}
		}
	}
	cout << "cnt: " << cnt << '\n';

	cout << "i = 5:\n";
	n = 5;
	cnt = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			for (int k = 1; k <= n; ++ k) {
				for (int l = 1; l <= n; ++ l) {
					for (int m = 1; m <= 5; ++ m) {
						if ((i + j + k + l + m) == i * j * k * l * m) {
							cout << i << ',' << j << ',' << k << ',' << l << ',' << m << '\n';
							++ cnt;
						}
					}
					
				}
			}
		}
	}
	cout << "cnt: " << cnt << '\n';

	return 0;
}
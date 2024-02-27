#include <bits/stdc++.h>
#define ll long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define N 1000009

using namespace std;

int p[N][5], s[N][5], n;
char c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	mst(p, 0);
	mst(s, 0);
	for (int i = 1; i <= 3 * n; ++ i) {
		cin >> c[i];
		for (int j = 0; j < 3; ++ j)
			p[i][j] = p[i - 1][j];
		++ p[i][c[i] - 'A'];
	}
	for (int i = 3 * n; i > 0; -- i) {
		for (int j = 0; j < 3; ++ j)
			s[i][j] = s[i + 1][j];
		++ s[i][c[i] - 'A'];
	}

	if (p[3 * n][0] == n && p[3 * n][1] == n) {
		cout << "0\n";
		return 0;
	}

	int j = 1;
	for (int i = 0; i <= 3 * n; ++ i) {
		// cout << "i: " << i << '\n';
		if (p[i][0] > n)
			break;
		int req = n - p[i][0];
		j = max(j, i + 1);
		while (j <= 3 * n && s[j][0] > req)
			++ j;
		while (j <= 3 * n && s[j][0] == req) {
			if (p[i][1] + s[j][1] == n) {
				cout << "1\n" << i + 1 << ' ' << j - 1 << " C\n";
				return 0;
			}
			if (p[i][2] + s[j][2] == n) {
				cout << "1\n" << i + 1 << ' ' << j - 1 << " B\n";
				return 0;
			}
			++ j;
		}
	}
	j = 1;
	for (int i = 0; i <= 3 * n; ++ i) {
		if (p[i][1] > n)
			break;
		int req = n - p[i][1];
		j = max(j, i + 1);
		while (j <= 3 * n && s[j][1] > req)
			++ j;
		while (j <= 3 * n && s[j][1] == req) {
			if (p[i][0] + s[j][0] == n) {
				cout << "1\n" << i + 1 << ' ' << j - 1 << " B\n";
				return 0;
			}
			if (p[i][2] + s[j][2] == n) {
				cout << "1\n" << i + 1 << ' ' << j - 1 << " A\n";
				return 0;
			}
			++ j;
		}
	}

	int na, nb, nc;
	for (int i = 1; i <= 3 * n; ++ i) {
		if (p[i][0] == n) {
			nb = n - p[i][1];
			nc = n - p[i][2];
			cout << "2\n" << i + 1 << ' ' << i + nb << " B\n" << i + nb + 1 << ' ' << 3 * n << ' ' << "C\n";
			return 0;
		}
		if (p[i][1] == n) {
			na = n - p[i][0];
			nc = n - p[i][2];
			cout << "2\n" << i + 1 << ' ' << i + na << " A\n" << i + na + 1 << ' ' << 3 * n << ' ' << "C\n";
			return 0;
		}
		if (p[i][2] == n) {
			na = n - p[i][0];
			nb = n - p[i][1];
			cout << "2\n" << i + 1 << ' ' << i + na << " A\n" << i + na + 1 << ' ' << 3 * n << ' ' << "B\n";
			return 0;
		}
	}

	return 0;
}
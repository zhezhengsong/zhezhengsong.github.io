#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int T, n, m;

vector< pii > a;

bool cmp_pii(pii x, pii y) {
	if (x.second < y.second || ((x.second == y.second) && (x.first < y.first)))
		return 1;
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		int x, y;
		cin >> x >> y;
		a.push_back(make_pair(x, y));
	}
	sort(a.begin(), a.end(), cmp_pii);

	for (auto x : a) {
		cout << x.first << ' ' << x.second << '\n';
	}

	return 0;
}
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

int T, n, m, a[N][N], cnt, ans;
char c[N][N];

queue< pair<int, int> > q;
queue< pair<int, int> > q2;

void col(int x, int y) {
	if (x > 0 && y > 0 && c[x][y] == 'X') {
		c[x][y] = '-';
		q2.push(make_pair(x, y));
		-- cnt;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (!q.empty())
		q.pop();
	while (!q2.empty())
		q2.pop();

	cin >> n >> m;
	cnt = 0, ans = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			cin >> c[i][j];
			cnt += (c[i][j] == 'X');
		}
	}
	
	for (int i = 0; i <= n + 1; ++ i) {
		for (int j = 0; j <= m + 1; ++ j) {
			if (c[i][j] != 'X')
				q.push(make_pair(i, j));
		}
	}
	// cout << cnt << '\n';
	
	while (cnt > 0) {
		while (!q.empty()) {
			pair <int, int> tmp = q.front();
			q.pop();
			int x = tmp.first, y = tmp.second;
			col(x - 1, y);
			col(x + 1, y);
			col(x, y - 1);
			col(x, y + 1);
		}
		while (!q2.empty()) {
			q.push(q2.front());
			q2.pop();
		}
		++ ans;
	}
	cout << ans << '\n';
	return 0;
}
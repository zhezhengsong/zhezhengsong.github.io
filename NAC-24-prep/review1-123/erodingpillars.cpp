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

int T, n, m;
double x[N], y[N];

int num[N], low[N], inde, res;
bool vis[N], flag[N];
vector<int> edge[N];
void Tarjan(int u, int father) {
	vis[u] = true;
	low[u] = num[u] = ++ inde;
	int child = 0;
	for (auto v : edge[u]) {
		if (!vis[v]) {
			++ child;
			Tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (father != u && low[v] >= num[u] && !flag[u]) {
				flag[u] = true;
				++ res;
			}
		}
		else if (v != father)
			low[u] = min(low[u], num[v]);
	}
	if (father == u && child >= 2 && !flag[u]) {
		flag[u] = true;
		++ res;
	}
}

double dis(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

bool JD(double thres) {
	for (int i = 0; i <= n; ++ i)
		edge[i].clear();
	for (int i = 0; i <= n - 1; ++ i) {
		for (int j = i + 1; j <= n; ++ j) {
			if (dis(i, j) <= thres) {
				edge[i].pb(j);
				edge[j].pb(i);
			}
		}
	}
	mst(vis, 0);
	mst(flag, 0);
	inde = 0;
	Tarjan(0, 0);
	
	int f = 1;
	for (int i = 1; i <= n; ++ i)
		if (flag[i] || !vis[i]) {
			f = 0;
			break;
		}
	return f;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	x[0] = 0;
	y[0] = 0;
	for (int i = 1; i <= n; ++ i) {
		cin >> x[i] >> y[i];
	}
	double l = 0, r = 3e9;
	while ((r - l) > 1.0 / 1000000.0) {
		double mid = (l + r) / 2.0;

		if (JD(mid) == 1)
			r = mid;
		else
			l = mid;
	}

	cout << setprecision(9) << l;

	return 0;
}

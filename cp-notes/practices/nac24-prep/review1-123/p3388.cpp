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

int num[100001], low[100001], inde, res;
bool vis[100001], flag[100001];
vector<int> edge[100001];
void Tarjan(int u, int father) {
	vis[u] = true;
	low[u] = num[u] = ++inde;
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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++ i) {
		int x, y;
		cin >> x >> y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	for (int i = 1; i <= n; ++ i)
		if (!vis[i]) {
			inde = 0;
			Tarjan(i, i);
		}
	cout << res << endl;
	for (int i = 1; i <= n; ++ i)
		if (flag[i])
			cout << i << " ";
	return 0;
}

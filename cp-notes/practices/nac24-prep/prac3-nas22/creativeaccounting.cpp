#include <bits/stdc++.h>
#define ll long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define N 30009
#define M 1000009
#define mod 998244353  //1000000007 1e9+9 984162944621615797 (__int128)
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define eps 1e-5
const unsigned seed = 2173412051;

using namespace std;

int n, l, h;
int a[N], presum[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> h;
	presum[0] = 0;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		presum[i] = presum[i - 1] + a[i];
	}
	int ans_min = N, ans_max = 0;
	for (int k = l; k <= h; ++ k) {
		
		for (int st = 0; st < k; ++ st) {
			int cur_ans = 0;
			int pre = 0;
			for (int i = st; i <= n; i += k) {
				int tmp = presum[i] - presum[pre];
				cur_ans += (tmp > 0);
				pre = i;
			}
			if (pre != n) {
				int tmp = presum[n] - presum[pre];
				cur_ans += (tmp > 0);
			}
			ans_max = max(ans_max, cur_ans);
			ans_min = min(ans_min, cur_ans);
		}
	}
	cout << ans_min << ' ' << ans_max << '\n';
	return 0;
}
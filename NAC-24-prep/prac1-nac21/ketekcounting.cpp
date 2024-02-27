#include <bits/stdc++.h>
#define ll long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define N 30009
#define mod 998244353

using namespace std;

int n, m, cntq[N], pow26[N], dp[2][N], dpPre[N];
string s;

int pairchar(int a, int b) {
	if (s[a] == '?' && s[b] == '?')
		return 26;
	else if (s[a] == '?' || s[b] == '?')
		return 1;
	else
		return s[a] == s[b];
}

int ers = 0;

int solve(int l, int r, int pt, int pr) {
	if (l > r) return 1;
	if (dp[pt][l] != -1 && r == pr)
		return dp[pt][l];
	int ml = n - 1 - l, mr = n - 1 - r;
	int sol = l == r ? pairchar(l, mr) : pairchar(l, mr) * pairchar(r, ml);
	if (sol == 0)
		return dp[pt ^ 1][l] = 0;
	sol = (ll)sol * solve(l + 1, r - 1, pt, pr) % mod;
	return dp[pt ^ 1][l] = sol;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.size();
	cntq[0] = (s[0] == '?');
	for (int i = 1; i < n; ++ i)
		cntq[i] = cntq[i - 1] + (s[i] == '?'); // Prefix sum of the number of "?"s.
	pow26[0] = 1;
	for (int i = 1; i < n + 1; ++ i)
		pow26[i] = (ll) pow26[i - 1] * 26 % mod; // 26 ^ i
	int ans = pow26[cntq[n - 1]];

	int t = 0;
	for (int r = 0; r < n / 2; ++ r) {
		t ^= 1; // Used for scrolling array
		mst(dp[t], -1);
		dpPre[r] = 0;
		for (int l = 0; l < r + 1; ++ l) {
			dpPre[r] += (ll) solve(l, r, t ^ 1, r - 1) * (l ? dpPre[l - 1] : 1) % mod;
			dpPre[r] %= mod;
		}
		int q = cntq[n - r - 2] - cntq[r];
		ans += (ll) dpPre[r] * pow26[q] % mod;
		ans %= mod;
	}
	cout << ans << '\n';
	return 0;
}
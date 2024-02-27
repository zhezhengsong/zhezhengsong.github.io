#include <bits/stdc++.h>
#define ll long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define N 15005
#define mod 998244353  //1000000007 1e9+9 984162944621615797 (__int128)

using namespace std;

int T, n, m;
string s;
int dp[N];

int getAmt(char a, char b) {
	if (a == '?' && b == '?')
		return 26;
	if (a == '?' || b == '?')
		return 1;
	if (a == b)
		return 1;
	return 0;
}

void force(int la, int ra, int lb, int rb) {
	int scale = 1;
	while (la >= 0 && ra < lb && rb < n) {
		scale = (scale * (ll)getAmt(s[la], s[lb])) % mod;
		if(la != ra) scale = (scale * (long long)getAmt(s[ra], s[rb])) % mod;
		if(scale == 0) break;
		dp[(rb-la+1)/2] += (scale * (long long)dp[(lb-ra)/2]) % mod;
		if(dp[(rb-la+1)/2] >= mod) dp[(rb-la+1)/2] -= mod;
		la--; lb--;
		ra++; rb++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int origs = 1;
	if(s.size() % 2) {
		int mid = s[s.size()/2];
		if (mid == '?')
			origs = 26;
		s = s.substr(0, s.size() / 2) + s.substr(s.size() / 2 + 1);
	}
	dp[0] = 1;
	n = s.size();
	int li = n / 2 - 1;
	int ri = n / 2;
	int curr = 1;
	int ni = 1;
	while (li >= 0 && ri < n && curr) {
		curr = (curr * (ll)(s[li --] == '?' ? 26 : 1)) % mod;
		curr = (curr * (ll)(s[ri ++] == '?' ? 26 : 1)) % mod;
		dp[ni ++] = curr;
	}
	for (int lhs = 0; lhs < n / 2; ++ lhs) {
		int li = (n / 2 - 1) - (lhs);
		int ri = li + 2 * lhs + 1;
		force(li, li, ri, ri);
		force(li-1, li, ri, ri+1);
	}

	int ans = (origs * (ll)dp[n/2]) % mod;
	cout << ans << "\n";
	return 0;
}
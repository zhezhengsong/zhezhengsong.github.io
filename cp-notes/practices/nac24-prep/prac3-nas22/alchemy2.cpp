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

int a[N], dp[N][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int l = s.length();

	for (int i = 0; i < l / 2; ++ i) {
		a[i] = (s[i] == s[l - i - 1]);
	}
	l /= 2;
	mst(dp, -1);
	if (a[0])
		dp[0][0] = 0;
	else
		dp[0][1] = 1;

	for (int i = 1; i < l; ++ i) {
		if (dp[i - 1][1] >= 0) {
			dp[i][0] = dp[i - 1][1] + 1;
			if (!a[i])
				dp[i][0] = min(dp[i][0], dp[i - 1][1]);
			if (dp[i][1] < 0)
				dp[i][1] = dp[i - 1][1] + 1; 
		}
		if (dp[i - 1][0] >= 0) {
			if (a[i]) {
				if (dp[i][0] < 0)
					dp[i][0] = dp[i - 1][0];
				else
					dp[i][0] = min(dp[i][0], dp[i - 1][0]);
			}
			else {
				if (dp[i][1] < 0)
					dp[i][1] = dp[i - 1][0] + 1;
				else
					dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
			}
		}
		// cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
	}
	int ans = 1000;
	if (dp[l - 1][0] > 0)
		ans = dp[l - 1][0];
	if (dp[l - 1][1] > 0)
		ans = min(ans, dp[l - 1][1]);
	if (ans == 1000)
		ans = 0;
	cout <<  ans << '\n';
	return 0;
}
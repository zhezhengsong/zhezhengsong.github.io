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

map <string, int> mp1, mp2;
vector < pair<string, int> > vt1, vt2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1, s3;
	int s2;
	for (;;) {
		cin >> s1;
		if (s1 == "------")
			break;
		cin >> s2 >> s3;
		mp1[s3] += s2 - stoi(s1);
	}
	for (;;) {
		cin >> s1;
		if (s1 == "======")
			break;
		cin >> s2 >> s3;
		mp2[s3] += s2 - stoi(s1);
	}
	for (auto x : mp1)
		mp1[x.first] = -x.second;
	for (auto x : mp2)
		mp1[x.first] += x.second;
	for (auto x : mp1)
		vt1.pb(x);
	sort(vt1.begin(), vt1.end());
	int f = 0;
	for (auto x : vt1)
		if (x.second != 0) {
			cout << x.first << ' ';
			if (x.second > 0)
				cout << '+';
			cout << x.second << '\n';
			f = 1;
		}
	if (!f)
		cout << "No differences found.\n";
	return 0;
}
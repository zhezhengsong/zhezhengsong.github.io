#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
#define all(v) (v).begin(), (v).end()
#define pb push_back

void dbg_out() { cerr << endl; }
template<typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const int BSZ = 500;

struct Range {
	int l, r, tin, tout;
};

struct Answer {
	int cnt, r, id;
	static Answer best(Answer lhs, Answer rhs) {
		if(lhs.cnt != rhs.cnt) {
			if(lhs.cnt > rhs.cnt) return lhs;
			else return rhs;
		} else if(lhs.r < rhs.r) {
			return lhs;
		} else {
			return rhs;
		}
	}
	Answer operator+(Answer rhs) {
		if(cnt == 0) return rhs;
		if(rhs.cnt == 0) return *this;
		rhs.cnt += cnt;
		return rhs;
	}
};

void solve() {
	int T; cin >> T;

	vector<Range> ranges;
	for(int t=0;t<T;t++) {
		int x; cin >> x;
		if(x >= 0) {
			int l = x, r; cin >> r;
			ranges.emplace_back(l, r, t, T);
		} else {
			int id = -x - 1;
			ranges[id].tout = t;
		}
	}

	int n = ranges.size();
	sort(all(ranges), [&](Range a, Range b) {
		if(a.r != b.r) return a.r < b.r;
		else return a.l < b.l;
	});

	// rem, id
	vector<pair<bool, int>> event(T);
	for(int id=0;id<n;id++) {
		auto [_l, _r, tin, tout] = ranges[id];
		event[tin] = {false, id};
		if(tout != T)
			event[tout] = {true, id};
	}

	// first ok next interval (ordered by start)
	vector<int> nxt(n);

	// active ranges;
	vector<bool> act(n);
	// id of a range in a bucket (ordered by start)
	vector<int> bid(n);

	vector<Answer> ans(T);
	for(int lid=0;lid<n;lid+=BSZ) {
		int rid = min(n-1, lid + BSZ - 1);
		int bsz = rid - lid + 1;

		// ranges ids of block ordered by start
		vector<int> ord(bsz);
		iota(all(ord), lid);
		sort(all(ord), [&](int ida, int idb) {
			return ranges[ida].l < ranges[idb].l;
		});
		for(int j=0;j<bsz;j++) bid[ord[j]] = j;

		vector<Answer> dp(bsz, {0, 0, 0});

		for(int id=0,j=0;id<=rid;id++) {
			int r = ranges[id].r;
			while(j < rid - lid + 1 && ranges[ord[j]].l <= r) j++;
			if(j == rid - lid + 1) nxt[id] = -1;
			else nxt[id] = j;
		}

		for(int t=0;t<T;t++) {
			auto [rem, eid] = event[t];
			if(lid <= eid && eid <= rid) {
				if(not rem) act[eid] = true;
				else act[eid] = false;
				for(int j=bsz-1;j>=0;j--) {
					int id = ord[j];
					auto &cur = dp[j];
					int nid = nxt[id];
					if(act[id]) cur = {1, ranges[id].r, id};
					else cur = {0, 0, 0};
					if(nid != -1) cur = cur + dp[nid];
					if(j != bsz-1) dp[j] = Answer::best(dp[j], dp[j+1]);
				}
			}
			if(ans[t].cnt != 0 && nxt[ans[t].id] != -1) {
				ans[t] = ans[t] + dp[nxt[ans[t].id]];
			}
			ans[t] = Answer::best(ans[t], dp[0]);
		}
	}

	for(int t=0;t<T;t++) cout << ans[t].cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
	return 0;
}
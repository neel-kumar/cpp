#include <bits/stdc++.h>
using namespace std;

long long n, a, b;
vector<pair<long long, long long>> tree[200001];
vector<long long> dist;

void dfs(long long v, long long p, long long d) {
	dist[v] = d;
	for(pair<long long, long long> i : tree[v]) {
		if(i.first == p) continue;
		dfs(i.first, v, d+i.second);
	}
}

signed main() {
	cin >> n >> a >> b; a--; b--;
	for(long long i = 1; i < n; i++) {
		long long x, y, z; cin >> x >> y >> z;
		x--; y--;
		tree[x].push_back(make_pair(y, z));
		tree[y].push_back(make_pair(x, z));
	}
	dist.resize(n);
	dfs(a, -1, 0);
	auto da = dist;
	dfs(b, -1, 0);
	auto db = dist;

	set<array<long long, 2>> diff;
	for(long long i = 0; i < n; i++) diff.insert({da[i]+db[i], i});
	cout << endl;
	long long ascore = 0, bscore = 0;
	for(long long i = 0; i < n; i++) {
		array<long long, 2> tp = *diff.rbegin(); diff.erase(tp);
		if(i%2 == 0) ascore += da[tp[1]];
		else bscore += db[tp[1]];
	}
	cout << ascore-bscore << endl;

	return 0;
}

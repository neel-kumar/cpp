#include <bits/stdc++.h>
using namespace std;

#define pii pair<long long, long long>

set<pii> s;
map<pii, bool> v;

signed main() {
	long long r, c, n; cin >> r >> c >> n;
	for(long long i = 0; i < n; i++) {
		long long a, b; cin >> a >> b;
		s.insert(make_pair(a, b));
	}

	long long M = 0;
	for(pii i : s) {
		if(v[i]) continue;
		queue<pii> q;
		q.push(i);
		long long cnt = 0;
		while(!q.empty()) {
			pii curr = q.front(); q.pop();
			if(v[curr]) continue;
			v[curr] = true;
			cnt += 4;
			if( s.count(make_pair(curr.first+1, curr.second)) ) q.push(make_pair(curr.first+1, curr.second)), cnt--;
			if( s.count(make_pair(curr.first-1, curr.second)) ) q.push(make_pair(curr.first-1, curr.second)), cnt--;
			if( s.count(make_pair(curr.first, curr.second+1)) ) q.push(make_pair(curr.first, curr.second+1)), cnt--;
			if( s.count(make_pair(curr.first, curr.second-1)) ) q.push(make_pair(curr.first, curr.second-1)), cnt--;
		}
		M = max(M, cnt);
	}
	cout << M << endl;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, t, k; cin>>n>>t>>k;
	int levels[k]; for(int i=0;i<k;i++) cin>>levels[i];

	int ans=0;
	priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
	set<array<int,4>> vis;
	// cost, distance, x till change, level
	pq.push({levels[0], 0, 4, 0});
	for(int i=0; i<n; i++) {
		array<int, 4> curr = pq.top(); pq.pop();
		while(vis.count(curr)) {
			curr = pq.top(); pq.pop();
		}
		ans += min(n-i, curr[2])*curr[0];
		i += min(n-i, curr[2])-1;

		if(curr[3]+1 != k) {
			array<int, 4> next = {0, curr[1], curr[2], curr[3]+1};
			next[0] = levels[next[3]] + next[1]*t;
			if(vis.count(next) == 0) {
				pq.push(next);
				vis.insert(curr);
			}
		}

		array<int, 4> next = {0, curr[1], curr[2], curr[3]};
		next[1] = curr[1]+1;
		next[2] = (next[1]+1)*4;
		next[0] = levels[next[3]] + next[1]*t;
		if(vis.count(next) == 0) {
			pq.push(next);
			vis.insert(curr);
		}
	}

	cout << ans << endl;
}

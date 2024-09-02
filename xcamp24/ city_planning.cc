#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, t, k; cin>>n>>t>>k;
	int levels[k]; for(int i=0;i<k;i++) cin>>levels[i];

	int ans=0;
	priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
	set<array<int,4>> vis;
	// cost, distance, x till change, level
	pq.push({levels[0], 0, 4, 0});
	vis.insert({levels[0], 0, 4, 0});
	for(int i=0; i<n; i++) {
	}
}

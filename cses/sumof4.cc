#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x; cin >> n >> x;
	int a[n]; for(int i=0; i<n; i++) cin>>a[i];

	map<int, vector<pair<int,int>>> m;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) if(i != j) {
			m[a[i]+a[j]].push_back({i, j});
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) if(i != j) {
			bool works = 0;
			pair<int,int> ans;
			for(pair<int,int> p : m[x-a[i]-a[j]]) if(p.f != i && p.s != i && p.f != j && p.s != j) {
				works = 1;
				ans = p;
			}
			if(works) {
				cout << i+1 << ' ' << j+1 << ' ' << ans.f+1 << ' ' << ans.s+1 << endl;
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<array<int,2>> a;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef LJ // g++ -DLJ
	freopen("mountains.in", "r", stdin); freopen("mountains.out", "w", stdout);
	#endif
	cin >> n;
	for(int i=1;i<=n;i++) {
		int x,y; cin>>x>>y;
		a.push_back({x-y,-(x+y)});
	}
	sort(a.begin(),a.end());
	int last=-1, ans=0;
	for(int i=0;i<n;i++) {
		int s=a[i][0],e=-a[i][1];
		if(e>last) {
			ans++;
			last=e;
		}
	}
	cout << ans << endl;
}

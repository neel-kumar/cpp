#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a;

void solve() {
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());

	int ans=0;
	for(int i=0; i<n && m-a[i]>=0; i++) {
		m-=a[i];
		ans++;
	}
	cout << n+1-(ans+(ans!=0 && ans!=n && m+a[ans-1]-a[ans]>=0)) << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n,k; cin >> n >> k;
	vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];

	k++;
	int ans=-1;
	for(int i=30;i>=0;i--) {
		bool over=false;
		vector<int> a2;
		for(int j : a) {
			if(!over) a2.push_back(j);
			else a2.back()^=j;
			if(j & (1<<i)) over=!over;
		}
		if(k&(1<<i)) {
			if(!over) ans=max(ans,(int)a2.size());
		} else {
			if(over) {
				cout << ans << endl;
				return;
			}
			a=a2;
		}
	}
	cout << ans << endl;
}

signed main() {
	int testcases; cin >> testcases; while(testcases--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,d;
int a[200000];
int p[200001];

array<int, 3> check(int x) { // {works, s,e}
	multiset<int> s;
	int sp = 0;
	for(int i=0; i<=n-x; i++) {
		int sum = p[i+x]-p[i];
		while(sp+d <= i+x) s.insert(p[sp+d]-p[sp]), sp++;
		if(sum-*s.rbegin()<= m) return {1, i, i+x-1};
		s.erase(s.find(p[i+d]-p[i]));
	}
	return {0, -1, -1};
}

signed main() {
	cin >> n >> m >> d;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
		p[i+1] = p[i]+a[i];
	}

	int l=d, r=n;
	while(l<r) {
		int mid = (l+r+1)/2;
		cerr << l << ' '<< r << ' ' << mid << " CHECKING\n";
		if(check(mid)[0]) l = mid;
		else r = mid-1;
	}

	array<int, 3> ans = check(l);
	cerr << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
	cout << l << endl << ans[1]+1 << ' ' << ans[2]+1 << endl;
}

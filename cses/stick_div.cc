#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int x,n; cin>>x>>n;
	int ans=0;
	multiset<int> s;
	for(int i=0;i<n;i++) {
		int x;cin>>x;
		s.insert(x);
	}

	while(s.size() > 1) {
		int a=*s.begin();
		s.erase(s.begin());
		int b=*s.begin();
		s.erase(s.begin());
		ans+=a+b;
		s.insert(a+b);
	}
	cout << ans << endl;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, m; cin>>n>>m;
	int ans = -1;
	set<int> s;
	for(int i=0;i<n;i++) {
		bool found = 0;
		int cnt=0;
		for(int j=0;j<m;j++) {
			char c; cin>>c;
			if(c == 'S' && !found) {
				cout << "-1\n";
				return 0;
			}
			if(c == 'S') found=0;
			cnt+=found;
			if(c == 'G') found=1;
		}
		s.insert(cnt);
	}
	cout << s.size() << endl;
}

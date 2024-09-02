#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	#ifndef LJ // g++ -DLJ
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif

	int n; cin>>n;
	stack<pair<int,int>> s;
	for(int i=0; i<n; i++) {
		int x; cin>>x;
		while(!s.empty() && s.top().first >= x) s.pop();
		cout << (s.empty() ? 0 : s.top().second) << ' ';
		s.push({x, i+1});
	}
	cout << endl;
}

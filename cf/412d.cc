#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, m; cin>>n>>m;
	set<pair<int, int>> s;
	for(int i=0; i<m; i++) {
		int a,b; cin>>a>>b;
		s.insert({a,b});
	}

	vector<int> ans = {1};
	for(int i=2; i<=n; i++) {
		ans.push_back(i);
		int j = ans.size()-1;
		while(j > 0 && s.count({ans[j-1], i})) {
			swap(ans[j], ans[j-1]);
			j--;
		}
	}

	for(int i=0; i<n; i++) cout<<ans[i]<<" ";
	cout << endl;
}

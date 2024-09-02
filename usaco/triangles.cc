#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
int n;
vector<pair<int,int>> v;
map<pair<int,int>,int> x,y;

void fill(map<pair<int,int>,int> &m) {
	for(int i=0; i<n; i++) {
		vector<pair<int,int>> same;
		same.push_back(v[i]);
		while(i<n-1 && v[i].first == v[i+1].first) {
			i++;
			same.push_back(v[i]);
		}
		m[same[0]] = 0;
		for(int i=1; i<same.size(); i++)
			m[same[0]] = m[same[0]] + (same[i].second-same[0].second);
		for(int i=1; i<same.size(); i++)
			m[same[i]] = m[same[i-1]] + ((2*i - same.size()) * (same[i].second - same[i-1].second));
	}
}

signed main() {
	#ifndef LJ // g++ -DLJ
	freopen("triangles.in", "r", stdin); freopen("triangles.out", "w", stdout);
	#endif
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++) {
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(),v.end());
	fill(x);
	for(pair<int,int> &i : v) swap(i.first,i.second);
	sort(v.begin(),v.end());
	fill(y);

	int ans=0;
	for(int i=0; i<n; i++) {
		ans += (y[v[i]] * x[{v[i].second,v[i].first}]) % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> g[1001];
int n;
vector<pair<int,int>> e,no;
map<int,int> xtoi;
map<int,int> dp;
set<int> stop;

int dfs(int v, int p) {
	if(dp.count(v)) return dp[v];
	if(g[v].size()==0) return dp[v]=0;
	int ret=0;
	for(int u : g[v]) {
		if(u!=p) ret += 1+dfs(u,v);
	}
	return dp[v]=ret;
}

bool cmp(pair<int,int> a, pair<int,int> b) { return a.second < b.second; }

signed main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		char c; int a,b; cin>>c>>a>>b;
		assert(xtoi.count(a)==0);
		xtoi[a]=i;
		if(c=='E') e.push_back({a,b});
		else no.push_back({a,b});
	}
	sort(no.begin(),no.end());
	sort(e.begin(),e.end(),cmp);

	for(pair<int,int> i : no) {
		for(pair<int,int> j : e) {
			if(j.second < i.second || j.first > i.first || stop.count(xtoi[j.first])) continue;
			if(j.second-i.second > i.first-j.first) {
				g[xtoi[j.first]].push_back(xtoi[i.first]);
				break;
			} else if(j.second-i.second < i.first-j.first) {
				g[xtoi[i.first]].push_back(xtoi[j.first]);
				stop.insert(xtoi[j.first]);
			}
		}
	}

	for(int i=0;i<n;i++) cout << dfs(i,-1) << endl;
}

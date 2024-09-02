#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,l;
map<int,int> m;
map<int,vector<int>> g;
vector<int> ans;

int a(int x) {
    return max(l - abs(l - x), 0LL);
}

int dfs(int node, int prev) {
    m[node]=1;
    if(g[node].size() == 1) return 1;
    int S=1;
    for(int ch: g[node]) {
        if(ch!=prev)
            S+=dfs(ch,node);
    }
    m[node]=S;
    return a(S);
}

void dfs2(int node, int mark, int prev, set<int> changes) {
	if( changes.count(a(m[node]+1)-a(m[node])) ) ans[node]=mark;

	set<int> nc;
	for(int j=-1;j<=1;j++)
		if( changes.count(a(m[node]+j)-a(m[node])) ) nc.insert(j);

	for(int ch : g[node]) {
		if(ch!=prev)
			dfs2(ch,mark,node,nc);
	}
}

void solve() {
    cin>>n>>l;
    g.clear();
    m.clear();
	ans.clear();
	ans.resize(n+1);
    int i;

    for(i=1;i<n;i++) {
        int in1,in2;cin>>in1>>in2;
        g[in1].push_back(in2);
        g[in2].push_back(in1);
    }
    dfs(1,-1);

	for(int j=-1;j<=1;j++)
		dfs2(1,j,-1,{j});

	for(i=1;i<=n;i++) cout << a(m[1])+ans[i] << ' ';
	cout << endl;
}

signed main() {
  int t;cin>>t;
  while(t--) solve();
}

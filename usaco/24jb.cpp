/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
using ld = long double;
#define f first
#define s second

int n;
int t[100001];
vi g[100001];
int dp[100001];

int d1(int v, int p) {
	int c=-1;
	for(int u:g[v]) {
		if(u==p) continue;
		c++;
		c+=d1(u,v);
	}
	if(c==-1)
		dp[v]=1;
	else
		dp[v]=c+1;
	return dp[v]-1;
}

int d2(int v, int p, int ts) {
	int c=t[v];
	for(int u:g[v]) {
		if(u==p) continue;
		c+=d2(u,v,ts);
	}
	/* cout << v << " dp: " << dp[v] << " c: " << c << endl; */
	return min(c,dp[v]);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin>>n;
	vi temp[n+1];
	for(int i=0;i<n;i++) {
		int a; cin >> a;
		temp[a].push_back(i);
	}
	for(int i=1;i<=n;i++)
		sort(temp[i].begin(),temp[i].end());

	for(int i=1;i<n;i++) {
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ts=d1(1,0)+1; // correct
	for(int i=1;i<=n;i++) {
		t[i]=0;
		for(int j : temp[i]) {
			if(j<ts)
				t[i]++;
			else
				break;
		}
	}

	// account for multiple timings
	cout << d2(1,0,ts) << endl;
}

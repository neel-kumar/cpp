/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") */
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef bitset<1000000001> bs;
/*
 * bs[i]        =>  set.count(i)
 * bs.set(i)    =>  set.insert(i)
 * bs.reset(i)  =>  set.erase(i)
 * bs.count()   =>  set.size()
 *
 * priority_queue <int, vector<int>, greater<int> > pq; minheap
 */
using ld = long double;
using ll = long long;
#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int t;cin>>t;
	while(t--) {
		int m,x;cin>>m>>x;
		m--;
		int dp[x+1];
		dp[1]=1;
		cout << "1 ";
		for(int i=2;i<=x;i++) {
			int p=m%i +1;
			if(dp[i-1]<p) dp[i]=dp[i-1];
			else dp[i]=dp[i-1]+1;
			cout << dp[i]; if(i!=x) cout<<' ';
		}
		cout << endl;
	}
}

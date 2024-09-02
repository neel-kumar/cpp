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

void solve() {
	int n,q,c;cin>>n>>q>>c;
	bool zz[n+1];
	int a[n+1]; for(int i=0;i<n;i++) {
		cin>>a[i+1];
		zz[i+1]=a[i+1]==0;
		if(zz[i+1]) a[i+1]=1;
	}
	int b[n+1]; memset(b,0,sizeof(b));
	for(int i=0;i<q;i++) {
		int x,y;cin>>x>>y;
		b[x]=y;
	}

	int i=1;
	while(i<=n) {
		int j=i+1;
		for(;j<b[i];j++) {
			if(b[j] && b[j]!=b[i]) {
				cout << "-1\n";
				return;
			}
			b[j]=b[i];
		}
		i=max(i+1,j);
	}

	i=1;
	for(;i<=n;i++) {
		if(!b[i]) continue;
		int psm=1; for(int j=1;j<=i;j++) psm=max(psm,a[j]);
		int bm=1; for(int j=i+1;j<b[i];j++) bm=max(bm,a[j]);
		/* printf("I %d --- psm %d --- bm %d --- a[b[i]] %d\n",i,psm,bm,a[b[i]]); */
		if(bm > psm) {
			bool fixed=false;
			for(int j=i;j>0;j--) {
				if(b[j]!=0 && b[j] < b[i]) {
					cout << "-1\n";
					return;
				}
				if(zz[j]) {
					/* if(a[b[j]]<=bm) { */
					/* 	if(zz[b[j]]) a[b[j]]=bm+1; */
					/* 	else continue; */
					/* } */
					a[j]=bm;
					fixed=true;
					break;
				}
			}
			if(!fixed) {
				cout << "-1\n";
				return;
			}
			psm=bm;
		}
		if(zz[b[i]]) {
			a[b[i]]=psm+1;
		} else if(a[b[i]] <= psm) {
			cout << "-1\n";
			return;
		}
		i=b[i]-1;
	}

	for(int i=0;i<n;i++) {
		if(a[i+1]>c) {
			cout << "-1\n";
			return;
		}
	}
	for(int i=0;i<n-1;i++) cout << max(a[i+1],1LL) << ' ';
	cout << max(a[n],1LL) << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int t;cin>>t;
	while(t--)
		solve();
}

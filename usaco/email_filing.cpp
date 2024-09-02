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
	int m,n,k;cin>>m>>n>>k;
	int a[n],l[n+1];
	bool filed[n];
	for(int i=0;i<n;i++) l[i+1]=-1;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		l[a[i]]=i;
		filed[i]=0;
	}

	int i=0,f=1;
	vector<int> win;
	vector<int> lft;
	for(;f<=n;f++) {
		for (auto it = win.begin(); it != win.end(); ++it) {
			if(a[*it]>=f && a[*it]<f+k) {
				filed[*it]=1;
				win.erase(it);
				it--;
			}
		}
		for(;i<=l[f] && i<n;i++) {
			if(win.size() == k) {
				lft.push_back(*win.begin());
				win.erase(win.begin());
			}
			if(a[i]>=f+k || a[i]<f) win.push_back(i);
			if(a[i]>=f && a[i]<f+k) filed[i]=1;
		}
		if(i==n) break;
	}

	for(;f<=n;f++) {
		if(filed[l[f]]) continue;
		for (auto it = win.begin(); it != win.end(); ++it) {
			if(a[*it]>=f && a[*it]<f+k) {
				filed[*it]=1;
				win.erase(it);
				it--;
			}
		}
		while(win.size() < k && lft.size()) {
			if(a[*lft.rbegin()] >= f+k) {
				win.push_back(*lft.rbegin());
			} else if(a[*lft.rbegin()] >= f) {
				filed[*lft.rbegin()]=1;
			}
			lft.pop_back();
		}
	}

	for(int j=0;j<n;j++) {
		if(!filed[j]) {
			cout << "NO\n";
			return;
		}
	}
	cout<<"YES\n";
}

signed main() {
	/* ios_base::sync_with_stdio(false); cin.tie(NULL); */
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int t;cin>>t;
	while(t--)
		solve();
}

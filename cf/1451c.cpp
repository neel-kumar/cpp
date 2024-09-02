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
		int n,k; cin>>n>>k;
		string as,bs;cin>>as>>bs;
		int a[27]={0},b[27]={0};
		for(int i=0;i<n;i++)
			a[as[i]-'a']++;
		for(int i=0;i<n;i++)
			b[bs[i]-'a']++;

		bool works=true;
		for(int i=0;i<26;i++) {
			if(a[i]<b[i] || (a[i]-b[i])%k) {
				works=false;
				break;
			}
			a[i+1]+=a[i]-b[i];
		}
		cout << (works?"Yes":"No") << endl;
	}

	return 0;
}

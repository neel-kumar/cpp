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

bool works;

int f(set<int> s, set<array<int,3>> bx1, set<array<int,3>> bx) {
	int ans=0;
	while(s.size() && s.size()>bx1.size()) {
		auto sit=s.begin();
		int slope=*sit;
		auto it1=--bx1.end(),it2=--bx.end();
		if( ((*it1)[0] > (*it2)[0]) ||
		((*it1)[0]==(*it2)[0] && ((*it1)[1]>(*it2)[1] )) ) {
			ans=max(ans, (*it1)[1]*slope+(*it1)[2]);
			bx1.erase(it1);
		} else {
			ans=max(ans, (*it2)[1]*slope+(*it2)[2]);
			bx.erase(it2);
		}
		s.erase(sit);
	}
	if(s.size() < bx1.size()) {
		works=0;
		return -1;
	}
	while(s.size()) {
		auto sit=s.begin();
		int slope=*sit;
		auto it1=bx1.end();
		it1--;
		ans=max(ans, (*it1)[1]*slope+(*it1)[2]);
		s.erase(sit);
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	/* freopen(".in", "r", stdin); */
	/* freopen(".out", "w", stdout); */

	int t;cin>>t;
	while(t--) {
		// 1s == positive
		set<array<int,3>> bx1,bx2,bx;
		set<int> s1,s2;
		int n,x1;cin>>n>>x1;
		for(int i=0;i<n;i++) {
			int y1,y2,x2;cin>>y1>>y2>>x2;
			bx1.insert({x2+y1,x2,y1});
			bx2.insert({x2+y2,x1,y2});

			bx.insert({x1+y1,x1,y1});
			bx.insert({x1+y2,x1,y2});
		}
		for(int i=0;i<4*n;i++) {
			int x;cin>>x;
			if(x>0) s1.insert(x);
			else s2.insert(-x);
		}

		cout << f(s1,bx1,bx) << ' ' << f(s2,bx2,bx) << endl;
	}
}
